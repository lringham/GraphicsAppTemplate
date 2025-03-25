from invoke import task
import os

DEFAULT_BUILD_MODE = "RelWithDebInfo"
APP_NAME = "app"
BUILD_DIR = "build"

@task
def deps(c, build_mode=DEFAULT_BUILD_MODE):
    "Install dependencies using Conan."
    c.run(f"conan install . --build=missing -of={BUILD_DIR}/conan --settings=build_type={build_mode}")

@task
def config(c, build_mode=DEFAULT_BUILD_MODE):
    "Configure the project using CMake."
    c.run(f"cmake --preset {build_mode}")

@task
def build(c, build_mode=DEFAULT_BUILD_MODE):
    "Build the project using CMake."
    c.run(f"cmake --build --preset={build_mode}")

@task
def launch(c, build_mode=DEFAULT_BUILD_MODE):
    "Launch the application."
    c.run(f"./{BUILD_DIR}/{build_mode}/{APP_NAME}")

@task
def clean(c):
    "Clean up build artifacts."
    c.run(f"rm -rf {BUILD_DIR} CMakeUserPresets.json compile_commands.json imgui.ini")

@task(pre=[config, build])
def run(c, build_mode=DEFAULT_BUILD_MODE):
    "Run the application after configuring and building."
    launch(c, build_mode)

@task(pre=[deps, config, build])
def setup(c, build_mode=DEFAULT_BUILD_MODE):
    "Setup the project: install dependencies, configure, and build."
    compile_commands_path = f"{BUILD_DIR}/{build_mode}/compile_commands.json"
    if os.path.exists(compile_commands_path):
        if os.path.exists("compile_commands.json") or os.path.islink("compile_commands.json"):
            os.remove("compile_commands.json")
        os.symlink(compile_commands_path, "compile_commands.json")
