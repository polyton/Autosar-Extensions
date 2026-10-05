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
- `build.bat` - Windows build command.

## Prerequisites

- Python 3.10 or newer
- `pip`
- GNU Make for the Unix-style build command

## Build alternatives

Choose the instructions for the machine where the documentation is built.

### Alternative 1: Ubuntu/Linux

Install the required system packages:

```bash
sudo apt update
sudo apt install python3 python3-venv python3-pip make
```

From the repository root, create an isolated environment, install the
documentation dependency, and build the HTML documentation:

```bash
python3 -m venv .venv
source .venv/bin/activate
python -m pip install -r 02_specs/requirements.txt
make -C 02_specs html
```

### Alternative 2: Windows

From a Command Prompt or PowerShell opened at the repository root:

```bat
python -m pip install -r 02_specs\requirements.txt
02_specs\build.bat
```

The batch file uses `02_specs\conf.py` and builds the HTML documentation.

The generated site is written to:

```text
02_specs/_build/html/index.html
```

Open that file in a browser to view the documentation locally.

## Clean generated output

```bash
make -C 02_specs clean
```
