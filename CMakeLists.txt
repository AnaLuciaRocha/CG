cmake_minimum_required (VERSION 3.15)

project (CG)

set(OpenGL_GL_PREFERENCE GLVND)

find_package(OpenGL REQUIRED)

add_subdirectory(external)

include_directories(
    external/glfw-3.3.3/include/GLFW/
    external/glm-0.9.7.1/
    external/glad/include/
)

set(ALL_LIBS
    ${OpenGL_LIBRARY}
    glfw
    glad
    glm
)

add_subdirectory(tp1)
add_subdirectory(tp1.ex1)
add_subdirectory(tp2_ex1)
add_subdirectory(tp2_ex2)
add_subdirectory(tp2_ex3)
add_subdirectory(tp2_ex4)

add_subdirectory(tp3_ex1)
