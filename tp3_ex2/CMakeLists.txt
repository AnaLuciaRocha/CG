add_executable(tp3_ex2 main.cpp)

target_link_libraries(tp3_ex2
    LINK_PUBLIC
        glfw
        glad
        ${CMAKE_DL_LIBS}
)
