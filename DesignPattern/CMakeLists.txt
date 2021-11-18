cmake_minimum_required (VERSION 3.1) 
set (CMAKE_C_STANDARD 17)
set (CMAKE_CXX_STANDARD 17)

project (CPPUtils)

include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/src")

add_subdirectory(src)
add_subdirectory(test)