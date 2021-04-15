add_executable(tp4 main.cpp)

target_link_libraries(tp4
    LINK_PUBLIC
        glfw
        glad
        ${CMAKE_DL_LIBS}
)
