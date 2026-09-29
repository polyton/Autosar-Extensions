# Autosar-Extensions

Extensions and tools for AUTOSAR development.

## Project structure

The repository is organized into numbered areas. The numeric prefixes make
the intended project flow visible at a glance:

| Folder | Purpose | Typical contents |
| --- | --- | --- |
| `01_docs` | General project documentation and references. | [AUTOSAR links](01_docs/autosar-links.md), project notes, and usage guides. |
| `02_specs` | Product, system, and software specifications. | Sphinx source, RST files, requirement descriptions, and traceability information. See the [specification guide](02_specs/README.md). |
| `03_arch` | Architecture definition and technical decisions. | [Architecture guide](03_arch/README.md), diagrams, interfaces, deployment views, and architecture decision records. |
| `04_sw` | Software implementation and AUTOSAR integration. | [Software guide](04_sw/README.md), source code, software components, configuration, build definitions, and integration adapters. |
| `05_tests` | Verification and validation assets. | [Test guide](05_tests/README.md), unit tests, integration tests, system tests, test data, and test reports. |
| `06_tools` | Development and maintenance utilities. | [Tools guide](06_tools/README.md), scripts, converters, generators, linters, and local automation. |
| `07_build` | Build and packaging outputs. | [Build guide](07_build/README.md), release packages, generated reports, and other reproducible build artifacts. |

Keep source files in the relevant numbered area. Generated files should be
placed in `07_build` or an ignored build directory and should not replace the
source documentation or implementation.

### Architecture basics

`03_arch` describes the system before implementation begins. It should answer
what the major elements are, how they communicate, where they are deployed,
and which design decisions constrain the implementation. Useful artifacts
include:

- System, ECU, and software-component context diagrams.
- AUTOSAR component, port, interface, and communication views.
- Deployment and allocation views for hardware and software.
- Architecture decision records with alternatives and consequences.

Architecture content should link back to the relevant requirements in
`02_specs` and provide enough detail for `04_sw` implementation decisions.

### Software basics

`04_sw` contains the implementation and AUTOSAR integration work. It should
answer how each allocated software element behaves and how it is built into
the target ECU. Typical content includes:

- Software-component source code, runnables, ports, and data types.
- ARXML or equivalent AUTOSAR configuration and interface definitions.
- RTE, BSW, middleware, and hardware-abstraction integration adapters.
- Build configuration and reproducible scripts; generated output belongs in
  `07_build` or an ignored build directory.

Software changes should trace to a software-level specification, an
architecture element, and one or more tests in `05_tests`.

## Specification documentation

The Sphinx documentation source is located in `02_specs` and is organized
into three levels:

- `00_product_view` - Product goals, features, and stakeholder constraints.
- `01_system_level` - System behavior, interfaces, diagnostics, and allocation.
- `02_software_level` - AUTOSAR software behavior, ports, runnables, and integration constraints.

See the [AUTOSAR links](01_docs/autosar-links.md) for official standards and
related automotive engineering resources.

See the [specification documentation guide](02_specs/README.md) for setup,
installation, and build instructions.
