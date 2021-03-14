add_executable(p1 main.cpp)

target_link_libraries(tp1
    LINK_PUBLIC
        glfw
        glad
        ${CMAKE_DL_LIBS}
)
