# Architecture

This folder describes the AUTOSAR system and software architecture before
implementation. Architecture decisions should trace to `02_specs` and provide
clear allocation guidance for `04_sw`.

## Structure

- `01_context/` - Product, vehicle, ECU, and external-system context.
- `02_component_model/` - AUTOSAR software-component decomposition and responsibilities.
- `03_interfaces/` - Ports, data types, service interfaces, signals, and communication paths.
- `04_deployment/` - Allocation of components and services to ECUs and execution environments.
- `05_decisions/` - Architecture decision records, alternatives, and consequences.
- `SW_Architecture.drawio` - Current editable software architecture diagram.

## Expected outputs

- Context and boundary diagrams.
- Component and dependency views.
- Communication and interface definitions.
- Deployment and allocation views.
- Reviewed architecture decisions.
