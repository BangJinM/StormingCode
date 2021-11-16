cmake_minimum_required (VERSION 3.1) 
set (CMAKE_C_STANDARD 17)
set (CMAKE_CXX_STANDARD 17)

project (CPPUtils)

set(CPPUtils 1.0.0)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include(Config)
SetPlatform()

include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/include")

set(UTILS_SRC "")
set(UTILS_HEADER "")

include(include/CMakeLists.txt)
include(src/CMakeLists.txt)

add_library(Utils ${UTILS_HEADER} ${UTILS_SRC})

option(utils_test "option for debug" ON)
if (utils_test)
    add_subdirectory(test)
endif()