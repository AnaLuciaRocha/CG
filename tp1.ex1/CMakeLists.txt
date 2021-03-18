add_executable(tp1.ex1 main.cpp)

target_link_libraries(tp1.ex1
    LINK_PUBLIC
        glfw
        glad
        ${CMAKE_DL_LIBS}
)
