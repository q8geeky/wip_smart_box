"""Static MCU clock audit. Does not modify registers or flash firmware."""
from __future__ import annotations

import argparse
from pathlib import Path
import re

ROOT=Path(__file__).resolve().parents[1]
REGISTER_PATTERN=r"\b{register}\s*=\s*(0x[0-9A-Fa-f]+|\d+)\s*;"


def read_register(source: str, register: str) -> int:
    pattern=REGISTER_PATTERN.format(register=re.escape(register))
    match=re.search(pattern,source)
    if not match:
        # Protected AVR registers are written through Microchip's
        # ccp_write_io((void*)&(REGISTER), VALUE) helper, not '='.
        protected = (
            r"ccp_write_io\s*\(\s*\(void\*\)\s*&\s*\("
            + re.escape(register)
            + r"\)\s*,\s*(0x[0-9A-Fa-f]+|\d+)\s*\)"
        )
        match = re.search(protected, source)
    if not match:
        raise ValueError(f"Missing assignment: {register}")
    return int(match.group(1),0)


def inspect_clock_sources(rtc_source: str, main_clock_source: str) -> list[str]:
    issues=[]
    rtc_clock=read_register(rtc_source,"RTC.CLKSEL")
    pit=read_register(rtc_source,"RTC.PITCTRLA")
    ext_enable=read_register(main_clock_source,"CLKCTRL.XOSC32KCTRLA")
    cpu_source=read_register(main_clock_source,"CLKCTRL.MCLKCTRLA")
    # The generated code comments identify 0x02 as an external
    # 32.768 kHz crystal source; verify selected clock on physical board.
    if rtc_clock == 0x02 and not (ext_enable & 0x01):
        issues.append(
            "RTC selects external XOSC32K, but the generated oscillator-enable bit is clear."
        )
    if (cpu_source & 0x03) == 0x02 and not (ext_enable & 0x01):
        issues.append(
            "CPU main clock appears to select XOSC32K while it is disabled."
        )
    if pit != 0x41:
        issues.append(
            f"PIT setting {pit:#04x} differs from assumed 512-cycle / 64-Hz divider."
        )
    return issues


def audit(root: Path=ROOT) -> list[str]:
    rtc=(root/"mcc_generated_files/src/rtc.c").read_text(encoding="utf-8")
    cpu=(root/"mcc_generated_files/mcc.c").read_text(encoding="utf-8")
    return inspect_clock_sources(rtc,cpu)


def main(argv=None) -> int:
    p=argparse.ArgumentParser(description="Check generated AVR clock selections; never flashes hardware.")
    p.add_argument("--strict",action="store_true",
                   help="Exit nonzero when any clock risk is detected")
    args=p.parse_args(argv)
    try:
        issues=audit()
    except (OSError,ValueError) as exc:
        p.exit(2,f"Clock audit failed: {exc}\n")
    if issues:
        print("CLOCK CONFIGURATION NEEDS PHYSICAL-BOARD REVIEW:")
        for issue in issues:
            print(" -",issue)
        print("No firmware configuration was changed.")
        return 1 if args.strict else 0
    print("No known static clock mismatch detected; real hardware checks are still required.")
    return 0


if __name__=="__main__":
    raise SystemExit(main())
