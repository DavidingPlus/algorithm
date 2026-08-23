message("-- Building on Unix ...")

# Configure ccache as the compiler launcher while keeping CMake's selected compiler.
find_program(CCACHE_EXECUTABLE ccache)
if(CCACHE_EXECUTABLE)
    message("-- Ccache executable found at: ${CCACHE_EXECUTABLE}")

    get_filename_component(CCACHE_REALPATH "${CCACHE_EXECUTABLE}" REALPATH)
    get_filename_component(C_COMPILER_REALPATH "${CMAKE_C_COMPILER}" REALPATH)
    get_filename_component(CXX_COMPILER_REALPATH "${CMAKE_CXX_COMPILER}" REALPATH)

    if(C_COMPILER_REALPATH STREQUAL CCACHE_REALPATH)
        message("-- C compiler already uses ccache.")
    else()
        set(CMAKE_C_COMPILER_LAUNCHER "${CCACHE_EXECUTABLE}")
    endif()

    if(CXX_COMPILER_REALPATH STREQUAL CCACHE_REALPATH)
        message("-- C++ compiler already uses ccache.")
    else()
        set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_EXECUTABLE}")
    endif()
else()
    message("-- Ccache not found; building without it.")
endif()

message("-- Using C Compiler: ${CMAKE_C_COMPILER} (${CMAKE_C_COMPILER_VERSION})")
message("-- Using C++ Compiler: ${CMAKE_CXX_COMPILER} (${CMAKE_CXX_COMPILER_VERSION})")
