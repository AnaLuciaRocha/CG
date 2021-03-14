cmake_minimum_required (VERSION 3.15)

project (CGr)

set(OpenGL_GL_PREFERENCE GLVND)

find_package(OpenGL REQUIRED)

add_subdirectory(external)

include_directories(
    external/glfw-3.3.3/include/GLFW/
    external/glad/include/
)

set(ALL_LIBS
    ${OpenGL_LIBRARY}
    glfw
    glad
)

add_subdirectory(tp1)
