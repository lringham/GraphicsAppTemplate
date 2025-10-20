from invoke import task
import os
import sys
import shutil

DEFAULT_BUILD_MODE = "RelWithDebInfo"
DEBUG_BUILD_MODE = "Debug"
RELEASE_BUILD_MODE = "Release"
APP_NAME = "app"
APP_NAME_LOWER = APP_NAME.lower()
BUILD_DIR = "build"

############ Utils ############
def rm(filename):
    """Remove a file"""
    try:
        if os.path.exists(filename) or os.path.islink(filename):
            os.remove(filename)
    except:
        pass

def rm_dir(dirname):
    """Remove a directory"""
    try:
        if os.path.exists(dirname):
            shutil.rmtree(dirname)
    except:
        pass

############ Tasks ############
@task
def deps(c, build_mode=DEFAULT_BUILD_MODE):
    """Install dependencies using Conan."""
    c.run(f"conan install . -b missing -of {BUILD_DIR}/conan --settings build_type={build_mode} -pr:a scripts/conan_profile.txt")

@task
def config(c, build_mode=DEFAULT_BUILD_MODE):
    """Configure the project using CMake."""
    c.run(f"cmake --preset {build_mode}")

@task
def build(c, build_mode=DEFAULT_BUILD_MODE):
    """Build the project using CMake."""
    c.run(f"cmake --build --preset={build_mode}")

@task
def launch(c, build_mode=DEFAULT_BUILD_MODE):
    """Launch the application."""
    if (sys.platform == "win32"):
        c.run(f"{BUILD_DIR}\\{build_mode}\\{APP_NAME}\\{APP_NAME_LOWER}.exe")
    else:
        c.run(f"./{BUILD_DIR}/{build_mode}/{APP_NAME_LOWER}")

@task
def clean(c):
    """Clean up build artifacts."""
    rm_dir(BUILD_DIR)
    for file in ["conan", "CMakeUserPresets.json"]:
        rm(file)

@task
def test(c, build_mode=DEFAULT_BUILD_MODE):
    """Run the tests."""
    if (sys.platform == "win32" ):
        c.run(f"ctest --test-dir .\\{BUILD_DIR}\\{build_mode}\\tests")
    else:
        c.run(f"ctest --test-dir ./{BUILD_DIR}/{build_mode}/tests")

@task
def run(c, build_mode=DEFAULT_BUILD_MODE):
    """Run the application after configuring and building."""
    config(c, build_mode)
    build(c, build_mode)
    launch(c, build_mode)

@task
def setup(c, build_mode=DEFAULT_BUILD_MODE):
    """Setup the project: install dependencies, configure, and build."""
    deps(c, build_mode)
    config(c, build_mode)
    build(c, build_mode)

    if (sys.platform == "linux" ):
        compile_commands_path = f"{BUILD_DIR}/{build_mode}/compile_commands.json"
        if os.path.exists(compile_commands_path):
            if os.path.exists("compile_commands.json") or os.path.islink("compile_commands.json"):
                os.remove("compile_commands.json")
            os.symlink(compile_commands_path, "compile_commands.json")