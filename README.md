# Graphics App Template
A basic app template based on OpenGL, Conan, CMake, and ImGUI. 

## Pre-requisites
```
curl -LsSf https://astral.sh/uv/install.sh | sh
```

## Setup
```
cd Workspace/App/  
uv venv && source .venv/bin/activate && uv sync  
conan profile detect  
inv setup  
```

## Running
```
inv run
```

## Conan profile
```
arch=x86_64
build_type=RelWithDebInfo
compiler=gcc
compiler.cppstd=gnu17
compiler.libcxx=libstdc++11
compiler.version=14
os=Linux
```