add_definitions(
    -DTW_STATIC
    -DTW_NO_LIB_PRAGMA
    -DTW_NO_DIRECT3D
    -DGLEW_STATIC
    -D_CRT_SECURE_NO_WARNINGS
)

add_subdirectory(glfw-3.3.3)
add_subdirectory(glm-0.9.7.1)

include_directories(
    glfw_3.3.3/include/GLFW/
    glm-0.9.7.1/glm/
)

add_subdirectory(glad)

include_directories(glad/include/glad/)
