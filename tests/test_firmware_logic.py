"""Host-side C regression tests for the application logic, not an XC8 firmware build."""
from __future__ import annotations
import ctypes
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "main.c"

# Standard seven-segment patterns A B C D E F G, 1=on.
SEGMENTS = {
    0: "1111110",
    1: "0110000",
    2: "1101101",
    3: "1111001",
    4: "0110011",
    5: "1011011",
    6: "1011111",
    7: "1110000",
    8: "1111111",
    9: "1111011",
}


class AVRLogicTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        if not shutil.which("gcc"):
            raise unittest.SkipTest("Host GCC is not installed.")
        cls.tmp = tempfile.TemporaryDirectory()
        lib_path = Path(cls.tmp.name) / "firmware_test.so"

        c = SOURCE.read_text(encoding="utf-8")
        c = c.replace('#include "mcc_generated_files/mcc.h"', "")
        c = c.replace("#include <util/atomic.h>", "")
        c = c.replace("int main(void)", "int firmware_main(void)")
        prelude = [
            "#include <stdint.h>",
            "static unsigned char seg[4][7];",
            "static int reset_pin = 0;",
            "static void (*pit_callback)(void) = 0;",
            "void SYSTEM_Initialize(void) {}",
            "void RTC_SetPITIsrCallback(void (*callback)(void)) { pit_callback = callback; }",
            "#define IO_PC6_GetValue() (reset_pin)",
            "#define COM1_SetLow() ((void)0)",
            "#define COM2_SetLow() ((void)0)",
            "#define ATOMIC_RESTORESTATE 0",
            "#define ATOMIC_BLOCK(x) for(int run_once = 1; run_once; run_once = 0)",
        ]
        for digit in range(1, 5):
            for seg_i, letter in enumerate("ABCDEFG"):
                prelude.append(f"#define SEG{digit}{letter}_SetHigh() (seg[{digit-1}][{seg_i}] = 1)")
                prelude.append(f"#define SEG{digit}{letter}_SetLow() (seg[{digit-1}][{seg_i}] = 0)")
        harness = """
void test_reset_segments(void) {
    for (int d=0;d<4;d++) for(int i=0;i<7;i++) seg[d][i]=99;
}
int test_segment(int d, int s) { return seg[d][s]; }
void test_reset_pin(int state) { reset_pin=state; }
void test_tick(int count) { while(count-- > 0) RTC_PITInterrupt(); }
int test_second(void) { return second; }
int test_minute1(void) { return minute1; }
int test_minute2(void) { return minute2; }
int test_hour1(void) { return hour1; }
int test_pit_ticks(void) { return pit_ticks; }
"""
        c_path = Path(cls.tmp.name) / "firmware_test.c"
        c_path.write_text("\n".join(prelude) + "\n" + c + "\n" + harness, encoding="utf-8")
        subprocess.run(
            ["gcc", "-std=c11", "-Wall", "-Wextra", "-shared", "-fPIC",
             str(c_path), "-o", str(lib_path)],
            check=True, capture_output=True, text=True,
        )
        cls.lib = ctypes.CDLL(str(lib_path))

    @classmethod
    def tearDownClass(cls):
        if hasattr(cls, "tmp"):
            cls.tmp.cleanup()

    def test_segments_for_all_40_cases(self):
        for digit in range(1,5):
            setter = getattr(self.lib, f"digit{digit}")
            for value, pattern in SEGMENTS.items():
                with self.subTest(display=digit, number=value):
                    self.lib.test_reset_segments()
                    setter(value)
                    actual = "".join(str(self.lib.test_segment(digit-1,i)) for i in range(7))
                    self.assertEqual(actual, pattern)

    def test_second_and_minute_are_clocked_at_64_pit_interrupts(self):
        self.lib.test_reset_pin(1)
        self.lib.test_tick(1)
        self.lib.test_reset_pin(0)
        self.lib.test_tick(63)
        self.assertEqual(self.lib.test_second(), 0)
        self.assertEqual(self.lib.test_pit_ticks(), 63)
        self.lib.test_tick(1)
        self.assertEqual(self.lib.test_second(), 1)
        self.assertEqual(self.lib.test_pit_ticks(), 0)
        self.lib.test_tick(59*64)
        self.assertEqual(self.lib.test_second(), 0)
        self.assertEqual(self.lib.test_minute1(), 1)
        self.lib.test_reset_pin(1)
        self.lib.test_tick(1)
        self.assertEqual(self.lib.test_minute1(), 0)

    def test_rtc_callback_is_registered_in_application(self):
        text = SOURCE.read_text(encoding="utf-8")
        self.assertRegex(text, r"RTC_SetPITIsrCallback\s*\(\s*RTC_PITInterrupt\s*\)")
        self.assertIn("#define PIT_CALLBACKS_PER_SECOND 64u", text)

    def test_generated_rtc_period_is_512_cycles(self):
        rtc = (ROOT / "mcc_generated_files" / "src" / "rtc.c").read_text(encoding="utf-8")
        self.assertRegex(rtc, r"RTC\.PITCTRLA\s*=\s*0x41\s*;")
        # Clock-source selection is an unresolved hardware issue documented in README;
        # this test intentionally does not pretend the physical oscillator works.


if __name__ == "__main__":
    unittest.main()
