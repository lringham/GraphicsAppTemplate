# Graphics App Template
A basic app template based on OpenGL, Conan, CMake, and ImGUI. 

## Linux setup
### Prerequisites
This is only done once to install the `uv` package manager
```sh
curl -LsSf https://astral.sh/uv/install.sh | sh
```

### Building
If you just want to build the application this script will get the dependencies, configure and build it.
```sh
bash scripts/build.sh
```

### Development
#### Setup
This should be done on first clone or if you change `pyproject.toml` or `conanfile.py`
```sh
uv venv
source .venv/bin/activate
uv sync
inv deps
```

#### Running
This will `configure`, `build`, and `launch` the application
```sh
inv run
```

### Conan profile
```
arch=x86_64
build_type=RelWithDebInfo
compiler=gcc
compiler.cppstd=gnu20
compiler.libcxx=libstdc++11
compiler.version=14
os=Linux
```

## Windows setup
