# Graphics App Template


A cross-platform template for graphics applications, designed to help you quickly start new OpenGL-based projects. This template integrates modern C++ practices with a modular framework, leveraging CMake for build management, Conan for dependency management, and Dear ImGui for immediate-mode graphical user interfaces.


## Project Structure

```
GraphicsAppTemplate/
├── App/
│   ├── include/           # Public headers (framework, GUI, etc.)
│   ├── src/               # Source files
│   └── thirdparty/        # Third-party code (e.g., ImGui bindings)
├── scripts/               # Build and Conan profiles
├── tests/                 # Unit and integration tests
├── tasks.py               # Python invoke tasks for automation
├── CMakeLists.txt         # Main CMake build script
├── conanfile.py           # Conan dependencies
├── LICENSE                # Project license
└── README.md              # This file
```


## Building & Setup
The project uses `Conan` and optionally `UV` for dependency management, but the CMake configuration is agnostic to those choices.


### Prerequisites
- [UV package manager](https://docs.astral.sh/uv/getting-started/installation/) (optional, for Python tooling)
- [Conan](https://conan.io/) (for C++ dependencies)
- [CMake](https://cmake.org/) (for build configuration)
- C++20 compatible compiler (e.g., GCC >= 10, Clang >= 10, MSVC >= 2019)


### Quick Start (Recommended)
1. Clone the repository:
   ```bash
   git clone https://github.com/lringham/GraphicsAppTemplate.git
   cd GraphicsAppTemplate
   ```
2. (Optional) Set up Python environment for automation:
    - **On Unix/macOS:**
       ```bash
       uv venv && source .venv/bin/activate && uv sync
       ```
    - **On Windows (cmd):**
       ```cmd
       uv venv && .venv\Scripts\activate && uv sync
       ```
    - **On Windows (PowerShell):**
       ```powershell
       uv venv; .venv\Scripts\Activate.ps1; uv sync
       ```
3. Install C++ dependencies and build:
   ```bash
   inv setup
   ```
4. Launch the application:
   ```bash
   inv launch
   ```

## Usage

The main application entry point is in `App/src/main.cpp`. To create your own app, subclass `framework::App` and override the virtual methods:

```cpp
class MyApp : public framework::App {
  void initialize() override { /* ... */ }
  void handleInput() override { /* ... */ }
  void render(float interp) const override { /* ... */ }
};
```

See `ExampleGUI.h/cpp` for a minimal ImGui panel example.

## Testing

Tests are located in the `tests/` directory and use [doctest](https://github.com/doctest/doctest).

To build and run tests:

```bash
inv build
inv test
```

## Contributing

Contributions are welcome! Please open issues or pull requests. For major changes, open an issue first to discuss your proposal.

**Coding style:** Follow modern C++ best practices. Use clang-format if possible.


## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
