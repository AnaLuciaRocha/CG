add_executable(tp2_ex1 main.cpp)

target_link_libraries(tp2_ex1
    LINK_PUBLIC
        glfw
        glad
        ${CMAKE_DL_LIBS}
)
