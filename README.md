# CG 2020/2021

## Create new project
1. Create a new folder tpx.exy
2. Copy CMakeLists.txt file and change 
    ```
    add_executable(tpx.exy main.cpp)

    target_link_libraries(tp1.ex1 .......
    ```
3. Go to CMakeLists.tct file (CG/) and add 
    ```
    add_subdirectory(tpx.exy)
    ```
4. Run ```CG/build$ cmake -S .. -B .```
5. run ```make```
6. execute ```./tpx.exy/tpx.exy```
