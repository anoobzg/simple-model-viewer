from conan import ConanFile
from conan.tools.cmake import CMakeDeps, CMakeToolchain

class PALRecipe(ConanFile):
    settings = "os", "build_type"

    def requirements(self):
        self.requires("assimp/5.4.2")
        self.requires("stb/cci.20230920")
        self.requires("sdl/2.30.7")
        self.requires("glm/1.0.1")
        self.requires("glew/2.2.0")
        self.requires("glfw/3.4")
        self.requires("zlib/1.3.1")
        self.requires("imgui/1.91.0")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.user_presets_path = False
        tc.generate()
        cd = CMakeDeps(self)
        cd.generate()