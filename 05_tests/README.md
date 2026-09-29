# Tests

This folder contains verification and validation assets for the AUTOSAR
extensions.

## Suggested structure

- `unit/` - Fast tests for one function, module, or software component.
- `integration/` - Tests for interactions between software modules, services, or interfaces.
- `system/` - Tests of ECU or system-level behavior against `02_specs/01_system_level`.
- `data/` - Controlled test vectors, fixtures, and input data.
- `reports/` - Generated test reports; keep large generated outputs out of source control when possible.

## Test traceability

Each test should identify the requirement or software behavior it verifies,
the test method, required environment, and result. Tests should be repeatable
from a documented command or script in `06_tools`.
