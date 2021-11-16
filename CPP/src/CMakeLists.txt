
if (CMAKE_HOST_WIN32)
list(APPEND UTILS_HEADER 
    src/StringHelperWin.cpp
)
elseif (CMAKE_HOST_APPLE)
elseif (CMAKE_HOST_UNIX)
list(APPEND UTILS_HEADER 
    src/StringHelperLinux.cpp
)
endif ()

list(APPEND UTILS_HEADER 
    src/StringHelper.cpp
)
