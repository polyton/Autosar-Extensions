# Software

This folder contains AUTOSAR software implementation and integration assets.
Software should trace to `02_specs/02_software_level`, architecture elements
in `03_arch`, and verification assets in `05_tests`.

## Structure

- `Autosar_Defines.h`, `Std_Macros.h`, `Std_Types.h` - Common AUTOSAR-style definitions and standard types.
- `ComServ/` - Communication services, message handling, signal processing, and end-to-end monitoring.
- `Debug/` - Development diagnostics, logging, and debug controls.
- `DiagEnv/` - Diagnostic environment and event management.
- `Libs/` - Reusable libraries and platform-independent data utilities.
- `MemStack/` - Memory and non-volatile-memory services.
- `MultiCore/` - Multicore synchronization and inter-core services.
- `SftyServ/` - Safety mechanisms, self-tests, safe-state handling, and safety goal support.
- `SysDrv/` - ECU and system drivers such as reset, watchdog, voltage, and SBC handling.
- `SysServ/` - System services such as ECU state, sleep, wake-up, and system management.

## Implementation guidance

- Keep public interfaces and configuration separate from private implementation details.
- Keep generated output in `07_build` or an ignored build directory.
- Document module ownership, dependencies, initialization order, and runtime assumptions.
- Add tests for each behavior changed by a software module.
