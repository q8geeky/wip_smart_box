# Smart Box AVR Firmware

An MPLAB X / Microchip Code Configurator project with a four-digit seven-segment time counter.

## Source and build

- Application logic: `main.c`
- Auto-generated pin, RTC and device configuration: `mcc_generated_files/`
- MPLAB X project configuration: `nbproject/`
- Build with the device and XC8 toolchain selected in `nbproject/configurations.xml`; do not substitute a generic desktop C compiler.

## Correctness fixes in this branch

1. **Every digit switch now terminates its case with `break;`.** Previously all ten cases fell through, so later cases overwrote earlier segment settings.
2. Time digits shared between the RTC interrupt and the display loop are declared `volatile uint8_t`.
3. The main display loop reads all four digits under `ATOMIC_BLOCK(ATOMIC_RESTORESTATE)`, preventing an interrupt from producing a mixed-time display.
4. Explicit function prototypes avoid implicit function declarations with stricter C compilers.

## Hardware verification checklist

The fixes have been reviewed statically but **not flashed to physical hardware**:

- Verify seven-segment polarity (active-high vs active-low).
- Verify `COM1`/`COM2` multiplexing behavior and brightness.
- Confirm the RTC PIT interrupt's actual period; the software assumes one callback per second.
- Check counting, reset input, digit transitions (09 → 10), and clock rollover.
- Build and flash using MPLAB X + the configured XC8 toolchain.

Do not publish new production firmware binaries until that review succeeds. Generated files and historical build artifacts are retained on this branch for comparison.

## Repository hygiene

`.gitignore` prevents *new* build products and IDE-private settings from being committed. It does not retroactively remove previously tracked files.
