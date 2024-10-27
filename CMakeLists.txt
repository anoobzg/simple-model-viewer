cmake_minimum_required(VERSION 3.12)
project(simple-model-viewer LANGUAGES C CXX)

include(cmake/entry/desktop-cpp.cmake)
__install_conan_requirements(MSVC_RUNTIME "static")

# viewer
__add_real_target(viewer exe SOURCE src/viewer.cpp
                                    src/imgui_impl_glfw.cpp
                                    src/imgui_impl_opengl3.cpp
                              DEF STB_IMAGE_IMPLEMENTATION
                                    )

target_compile_features(viewer PRIVATE cxx_std_17)
set_target_properties(viewer PROPERTIES CXX_EXTENSIONS OFF)
target_include_directories(viewer PRIVATE src)

# compile options
target_compile_options(viewer PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic>
)

# externals
add_subdirectory(externals)

# OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(viewer PRIVATE OpenGL::GL)

# glad
target_link_libraries(viewer PRIVATE glad)

# GLFW
find_package(glfw3)
target_link_libraries(viewer PRIVATE glfw)

# glm
find_package(glm)
target_link_libraries(viewer PRIVATE glm::glm)

# assimp
find_package(assimp)
target_link_libraries(viewer PRIVATE assimp::assimp)

# imgui
find_package(imgui)
target_link_libraries(viewer PRIVATE imgui::imgui)

# imgui_glfw_opengl3
# target_link_libraries(viewer PRIVATE imgui_glfw_opengl3)

# stb
find_package(stb)
target_link_libraries(viewer PRIVATE stb::stb)