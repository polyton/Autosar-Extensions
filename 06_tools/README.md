# Tools

This folder contains reusable development and maintenance utilities.

## Suggested structure

- `scripts/` - Small command-line scripts for local workflows.
- `generators/` - Code, ARXML, or documentation generators.
- `converters/` - Format conversion and import/export utilities.
- `checks/` - Linters, validators, and consistency checks.
- `ci/` - Continuous-integration helpers and repeatable verification commands.

Tools should document their inputs, outputs, dependencies, and usage command.
They should not silently modify source files or commit generated output.
