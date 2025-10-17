#!/usr/bin/env bash

uv venv
source .venv/bin/activate
uv sync
inv setup --build-mode=Release