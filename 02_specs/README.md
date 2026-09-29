# AUTOSAR specifications

This folder contains the Sphinx documentation for the AUTOSAR specification
levels used by the project.

## Source structure

- `00_product_view/` - Product goals, features, and stakeholder constraints.
- `01_system_level/` - System behavior, interfaces, diagnostics, and allocation.
- `02_software_level/` - AUTOSAR software behavior, ports, runnables, and integration constraints.
- `index.rst` - Sphinx entry point and table of contents.
- `conf.py` - Minimal Sphinx configuration.
- `Makefile` - Local build commands.

## Prerequisites

- Python 3.10 or newer
- `pip`
- GNU Make

## Install documentation tools

From the repository root, install the Python documentation dependency:

```bash
python3 -m pip install -r 02_specs/requirements.txt
```

## Build HTML documentation

Run the build from the repository root:

```bash
make -C 02_specs html
```

The generated site is written to:

```text
02_specs/_build/html/index.html
```

Open that file in a browser to view the documentation locally.

## Clean generated output

```bash
make -C 02_specs clean
```
