# Smart Box AVR Firmware

Four-digit seven-segment counter firmware for the ATmega4809, based on Microchip MCC-generated drivers.

## Building

Use MPLAB X and the XC8 AVR compiler with the device and project settings in `nbproject/configurations.xml`. The existing generated drivers retain their original license.

## Application fixes (review branch)

- Every digit case has a `break`; the former switches unintentionally executed every later case.
- The RTC-updated digit counters are declared `volatile uint8_t`; the display uses an atomic snapshot.
- Register `RTC_PITInterrupt` via `RTC_SetPITIsrCallback`. The generated driver only invokes callbacks after registration.
- `RTC.PITCTRLA=0x41` means one interrupt per **512 RTC clock cycles**, which is **64 interrupts/sec** with a 32.768 kHz RTC clock. A 64-callback divider now produces one logical second.

## Critical board-clock verification before flashing

The existing **generated** driver config has:

```text
RTC.CLKSEL = 0x02              (external 32.768 kHz crystal source)
RTC.PITCTRLA = 0x41            (PIT 512 cycles)
CLKCTRL.XOSC32KCTRLA = 0x00   (external oscillator disabled)
CLKCTRL.MCLKCTRLA = 0x02      (CPU selects external crystal clock)
```

The source selections appear **internally inconsistent** and could prevent clock/timer operation. Confirm which oscillator the real board has and configure the appropriate enable and source registers in MCC before deploying. This PR deliberately does not guess the board clock hardware.

## Manual verification required

- Confirm CPU and RTC oscillator clock on real ATmega4809 hardware.
- Verify seven-segment polarity, COM1/COM2 multiplexing, brightness.
- Verify PC6 reset and one displayed minute against real time.
- Verify rollover behavior (09→10, 59→60 and 99 hours if relevant).
- Build/flash with XC8; the hosted static source checks are not an embedded build.

The existing generated files, pins and historical binary artifacts were not changed. `.gitignore` only excludes future build output.
