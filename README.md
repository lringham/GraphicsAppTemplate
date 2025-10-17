# Graphics App Template

A cross-platform template for graphics applications, designed to help you quickly start new OpenGL-based projects. This template integrates modern C++ practices with a modular framework, leveraging CMake for build management, Conan for dependency management, and Dear ImGUI for immediate-mode graphical user interfaces.

## Building
The project is setup to use `Conan` and `UV` for dependency management but the CMake configuration is agonostic to those choices.

### Prerequisites
- [UV package manager](https://docs.astral.sh/uv/getting-started/installation/)
- C++20 compatible compiler (e.g., GCC >= 10, Clang >= 10, MSVC >= 2019)

### Quick Start (Recommended)
1. Clone the repository:
   ```bash
   git clone https://github.com/lringham/GraphicsAppTemplate.git
   cd GraphicsAppTemplate
   ```
2. Run `uv venv && source .venv/bin/activate && uv sync`
2. Run `inv setup launch`
