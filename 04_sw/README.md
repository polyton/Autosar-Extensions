# Software

This folder contains AUTOSAR software implementation and integration assets.
Its top-level layout follows the product architecture in
[`02_specs/00_product_view/PtoductView.html`](../02_specs/00_product_view/PtoductView.html).
Software should trace to `02_specs/02_software_level`, architecture elements
in `03_arch`, and verification assets in `05_tests`.

## Structure

- `Autosar_Defines.h`, `Std_Macros.h`, `Std_Types.h` - Common definitions and standard types.
- `Extensions/` - In-house software extensions grouped by their product-architecture responsibility:
  - `SystemMode/` - `SysMng`, `SleepCtrl`, and `WupMon`.
  - `SystemServices/` - `RstMng` and `WdgMng`.
  - `Communication/` - `ComMsgHdl`, `ComMsgMon`, `ComSigR`, and `E2eMon`.
  - `MemoryAbstraction/` - `NvmCtrlCe`.
  - `DiagnosticEnvironment/` - `EventDataHdl`.
  - `Debug/` - `DataHistory`, `DevMsgCtrl`, and `RunLogTime`.
- `BSW/` - Basic software building blocks:
  - `IOHwAb/` - I/O hardware abstraction SWCs: `IOHwAb`, `SnsrMon`, `GpioMux`, `ShiftReg`, and `LatchCtrl`.
  - `MultiCore/` - `SecICR` and `SpinLock`.
- `LIB/` - Reusable utilities such as `LUT` and `PrtData`.
- `CDD/` - Complex device drivers:
  - `SafetyServices/` - `SafeStateMng`, `FaultReaction`, and monitoring components:
    - `HWMonitoring/` - `HwFaultHdl` and `Mon_SWC`.
    - `MCUMonitoring/` - `McuFaultHdl` and `Mon_SWC`.
  - `SystemDrivers/` - `SbcDrv`, `VarHdl`, and `VoltMon`.

The I/O hardware abstraction modules and the remaining safety components are
architecture placeholders awaiting implementation. `SafeStateMng` has the
current safety-service implementation files.

Each module follows the `Cfg/`, `Core/`, and `Ext/` layout. Core modules expose
their basic interface from a matching `.h` file and include an initialization
stub in the matching `.c` file where implementation is pending.

## Implementation guidance

- Keep public interfaces and configuration separate from private implementation details.
- Keep generated output in `07_build` or an ignored build directory.
- Document module ownership, dependencies, initialization order, and runtime assumptions.
- Add tests for each behavior changed by a software module.
