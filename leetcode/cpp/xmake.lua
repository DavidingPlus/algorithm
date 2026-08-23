-- Keep the LeetCode layout equivalent to leetcode/cpp/CMakeLists.txt:
-- one common static library and one executable per solution file.

-- Linux uses GCC's built-in bits/stdc++.h. On Windows, resolve the same
-- include to the repository-local compatibility header instead.
if is_plat("windows") then
    add_includedirs("leetcode/editor/common")
end

target("common")
    set_kind("static")
    set_languages("c++20")
    add_files("leetcode/editor/common/*.cpp")

local used_target_names = {}

local function add_solution(source_file, language)
    local source_name = path.basename(source_file)
    local output_name = source_name .. "_" .. language

    -- Use the source filename as the target name so xmake run's target
    -- completion shows the same descriptive name as the executable.
    local target_name = output_name
    local target_index = 1
    while used_target_names[target_name] do
        target_name = output_name .. "_" .. target_index
        target_index = target_index + 1
    end
    used_target_names[target_name] = true

    target(target_name)
        set_kind("binary")
        set_languages("c++20")
        set_basename(output_name)
        add_files(source_file)
        add_deps("common")
end

local function add_solutions(language)
    local source_files = os.files("leetcode/editor/" .. language .. "/*.cpp")
    table.sort(source_files)
    for _, source_file in ipairs(source_files) do
        add_solution(source_file, language)
    end
end

add_solutions("cn")
add_solutions("en")
