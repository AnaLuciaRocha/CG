# CG 2020/2021

## Create new project
1. Create a new folder tpx.exy
2. Copy CMakeLists.txt file and change 
    ```
    add_executable(tpx_exy main.cpp)

    target_link_libraries(tp1_ex1 .......
    ```
3. Go to CMakeLists.tct file (CG/) and add 
    ```
    add_subdirectory(tpx_exy)
    ```
4. Run ```CG/build$ cmake -S .. -B .```
5. run ```make```
6. execute ```./tpx_exy/tpx_exy```
