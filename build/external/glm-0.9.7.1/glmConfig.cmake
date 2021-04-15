set(GLM_VERSION "0.9.7")
set(GLM_INCLUDE_DIRS "/home/ana/Documents/CG/external/glm-0.9.7.1")

if (NOT CMAKE_VERSION VERSION_LESS "3.0")
    include("${CMAKE_CURRENT_LIST_DIR}/glmTargets.cmake")
endif()
