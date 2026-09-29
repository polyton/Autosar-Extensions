"""Minimal Sphinx configuration for AUTOSAR specifications."""

from datetime import datetime

project = "AUTOSAR Extensions Specifications"
author = "Autosar Extensions"
copyright = f"{datetime.now().year}, {author}"

extensions = []

source_suffix = ".rst"
root_doc = "index"
master_doc = "index"

exclude_patterns = ["_build"]

html_theme = "alabaster"
html_title = project
html_show_sphinx = False
