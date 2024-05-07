cmake_minimum_required(VERSION 3.12)
project(hello_algo CXX)

set(CMAKE_CXX_STANDARD 11)

# configuring ccache cross platform
if(CMAKE_HOST_WIN32)
    add_compile_options ("/Z7")  # To satisfy Ccache

    find_program (CCACHE_EXECUTABLE ccache)
    if (CCACHE_EXECUTABLE)
        message ("-- Ccache executable found at: ${CCACHE_EXECUTABLE}")
        file (COPY "${CCACHE_EXECUTABLE}" DESTINATION "${PROJECT_BINARY_DIR}")
        file (RENAME "${PROJECT_BINARY_DIR}/ccache.exe" "${PROJECT_BINARY_DIR}/cl.exe")
        set (CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<$<CONFIG:Debug,RelWithDebInfo>:Embedded>")
        set (CMAKE_VS_GLOBALS
            "CLToolExe=cl.exe"
            "CLToolPath=${PROJECT_BINARY_DIR}"
            "TrackFileAccess=false"
            "UseMultiToolTask=true"
            "DebugInformationFormat=OldStyle"
        )
    else ()
        message ("-- CCache not found.")
    endif ()

elseif(CMAKE_HOST_UNIX)
    set (CMAKE_C_COMPILER "gcc")
    set (CMAKE_CXX_COMPILER "g++")
    message ("-- Using C Compiler: ${CMAKE_C_COMPILER} (${CMAKE_C_COMPILER_VERSION})")
    message ("-- Using C++ Compiler: ${CMAKE_CXX_COMPILER} (${CMAKE_CXX_COMPILER_VERSION})")

else ()
    message (FATAL_ERROR "Unknown platform.")

endif ()

include_directories(./include)

add_subdirectory(chapter_computational_complexity)
add_subdirectory(chapter_array_and_linkedlist)
add_subdirectory(chapter_stack_and_queue)
add_subdirectory(chapter_hashing)
add_subdirectory(chapter_tree)
add_subdirectory(chapter_heap)
add_subdirectory(chapter_graph)
add_subdirectory(chapter_searching)
add_subdirectory(chapter_sorting)
add_subdirectory(chapter_divide_and_conquer)
add_subdirectory(chapter_backtracking)
add_subdirectory(chapter_dynamic_programming)
add_subdirectory(chapter_greedy)
