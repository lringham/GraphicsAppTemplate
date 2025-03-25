from conan import ConanFile
from conan.tools.files import copy
import os
import inspect, json, pickle, base64

class CompressorRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("glfw/3.4")
        self.requires("glad/0.1.36")
        self.requires("imgui/cci.20230105+1.89.2.docking")
        self.requires("spdlog/1.15.1")
        
    def configure(self):
        self.options['glad'].shared = False
        self.options['glad'].fPIC = True
        self.options['glad'].no_loader = False
        self.options['glad'].spec = 'gl'
        self.options['glad'].gl_profile = 'core'
        self.options['glad'].gl_version = '4.6'

    def build_requirements(self):
        self.tool_requires("cmake/3.22.6")

    def generate(self):
        src = self.dependencies["imgui"].cpp_info.srcdirs[0]
        copy(self, "*imgui_impl_glfw.cpp", src, dst="imgui")
        copy(self, "*imgui_impl_glfw.h", src, dst="imgui/include")
        copy(self, "*imgui_impl_opengl3.cpp", src, dst="imgui")
        copy(self, "*imgui_impl_opengl3.h", src, dst="imgui/include")
        copy(self, "*imgui_impl_opengl3_loader.h", src, dst="imgui/include")

