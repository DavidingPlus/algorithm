cmake_minimum_required(VERSION 3.29)
project(cpp_template)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

# 收集公共代码
file(GLOB_RECURSE COMMON_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/leetcode/editor/common/*.cpp"
)

# 编译公共代码为库
add_library(common STATIC ${COMMON_SOURCES})

# 收集包含 main 函数的代码
file(GLOB_RECURSE MAIN_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/leetcode/editor/cn/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/leetcode/editor/en/*.cpp"
)

# 为每个包含 main 函数的文件生成可执行文件
foreach(source_file IN LISTS MAIN_SOURCES)
    # 使用源文件名和语言目录生成有语义的可执行文件名
    get_filename_component(source_name "${source_file}" NAME)
    string(REGEX REPLACE "\\.cpp$" "" source_name "${source_name}")
    get_filename_component(dir "${source_file}" DIRECTORY)        # 提取所在目录
    get_filename_component(language "${dir}" NAME)
    set(output_name "${source_name}_${language}")

    # CMake 逻辑 target 不能使用中文等字符，使用题号或清洗后的文件名作为内部名称
    string(REGEX MATCH "^[0-9]+" problem_id "${source_name}")
    if(problem_id)
        set(base_target_name "lc_${problem_id}_${language}")
    else()
        string(REGEX REPLACE "[^A-Za-z0-9_]" "_" safe_source_name "${source_name}")
        set(base_target_name "lc_${safe_source_name}_${language}")
    endif()

    # 同一题号存在多个文件时，为内部 target 添加递增后缀
    set(target_name "${base_target_name}")
    set(target_index 1)
    while(TARGET "${target_name}")
        set(target_name "${base_target_name}_${target_index}")
        math(EXPR target_index "${target_index} + 1")
    endwhile()

    # 生成可执行文件并链接公共库
    add_executable("${target_name}" "${source_file}")
    set_target_properties("${target_name}" PROPERTIES OUTPUT_NAME "${output_name}")
    target_link_libraries("${target_name}" common)
endforeach()
