#!/usr/bin/env bash

uv venv
source .venv/bin/activate
uv sync
conan profile detect -e
inv setup --build-mode=Release