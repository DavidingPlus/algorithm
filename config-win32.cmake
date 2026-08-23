message("-- Building on Win32 ...")

message("-- Using C Compiler: ${CMAKE_C_COMPILER} (${CMAKE_C_COMPILER_VERSION})")
message("-- Using C++ Compiler: ${CMAKE_CXX_COMPILER} (${CMAKE_CXX_COMPILER_VERSION})")

# Use warning level /W2.
option(SUPRESS_W3_WARNINGS "Configure warning level to /W2" ON)
if(SUPRESS_W3_WARNINGS)
    add_compile_options("/W2")
endif()

# Configure MSVC with ccache. Ccache requires MSVC as the underlying compiler.
add_compile_options("/Z7")

find_program(CCACHE_EXECUTABLE ccache)
if(CCACHE_EXECUTABLE)
    message("-- Ccache executable found at: ${CCACHE_EXECUTABLE}")
    file(COPY "${CCACHE_EXECUTABLE}" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
    file(RENAME "${CMAKE_CURRENT_BINARY_DIR}/ccache.exe" "${CMAKE_CURRENT_BINARY_DIR}/cl.exe")
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<$<CONFIG:Debug,RelWithDebInfo>:Embedded>")
    set(CMAKE_VS_GLOBALS
        "CLToolExe=cl.exe"
        "CLToolPath=${CMAKE_CURRENT_BINARY_DIR}"
        "TrackFileAccess=false"
        "UseMultiToolTask=true"
        "DebugInformationFormat=OldStyle"
    )
else()
    message("-- Ccache not found; building without it.")
endif()
