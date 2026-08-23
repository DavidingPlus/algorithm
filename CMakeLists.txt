cmake_minimum_required (VERSION 3.29)

project (algorithm)

if (CMAKE_HOST_UNIX)
    include (config-unix.cmake)
elseif (CMAKE_HOST_WIN32)
    include (config-win32.cmake)
else ()
    message (FATAL_ERROR "Unknown platform.")
endif ()

add_subdirectory (leetcode/cpp)
add_subdirectory (hello-algo)
