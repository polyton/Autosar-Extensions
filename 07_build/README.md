# Build outputs

This folder contains reproducible build and packaging outputs. It is separate
from source code and documentation so generated files do not obscure reviewable
project content.

## Structure

- `vscode/` - Workspace files for local development.
- `docs/` - Exported documentation packages, when published as build output.
- `reports/` - Build, test, coverage, and traceability reports.
- `packages/` - Release archives or installable deliverables.

Generated output should be reproducible from source and documented commands.
Large temporary files should remain ignored rather than being committed.
