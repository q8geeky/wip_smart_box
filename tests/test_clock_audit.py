"""Self-tests for clock diagnostic (not physical board verification)."""
from __future__ import annotations
import unittest
from tools.clock_audit import audit, inspect_clock_sources


class ClockAuditTests(unittest.TestCase):
    def test_existing_configuration_is_flagged(self):
        findings=audit()
        self.assertGreaterEqual(len(findings),1)
        self.assertTrue(any("XOSC32K" in entry for entry in findings))

    def test_synthetic_clock_enabled(self):
        rtc="RTC.CLKSEL = 0x02; RTC.PITCTRLA = 0x41;"
        clk="CLKCTRL.XOSC32KCTRLA = 0x01; CLKCTRL.MCLKCTRLA = 0x02;"
        self.assertEqual(inspect_clock_sources(rtc,clk),[])

    def test_pit_change_warned(self):
        rtc="RTC.CLKSEL = 0x02; RTC.PITCTRLA = 0x40;"
        clk="CLKCTRL.XOSC32KCTRLA = 0x01; CLKCTRL.MCLKCTRLA = 0x02;"
        self.assertTrue(any("PIT" in issue for issue in inspect_clock_sources(rtc,clk)))


if __name__=="__main__":
    unittest.main()
