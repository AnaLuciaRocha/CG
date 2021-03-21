add_executable(tp2_ex4 main.cpp)

target_link_libraries(tp2_ex4
    LINK_PUBLIC
        glfw
        glad
        ${CMAKE_DL_LIBS}
)
