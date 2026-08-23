-- Keep the LeetCode layout equivalent to leetcode/cpp/CMakeLists.txt:
-- one common static library and one executable per solution file.

target("common")
    set_kind("static")
    set_languages("c++20")
    add_files("leetcode/editor/common/*.cpp")

local used_target_names = {}

local function add_solution(source_file, language)
    local source_name = path.basename(source_file)
    local output_name = source_name .. "_" .. language

    -- Target names must be portable even when the source filename contains
    -- Chinese characters, spaces, or punctuation.
    local problem_id = source_name:match("^(%d+)")
    local base_target_name
    if problem_id then
        base_target_name = "lc_" .. problem_id .. "_" .. language
    else
        local safe_source_name = source_name:gsub("[^A-Za-z0-9_]", "_")
        base_target_name = "lc_" .. safe_source_name .. "_" .. language
    end

    -- Match CMake's behavior when more than one file maps to the same
    -- problem/language target name.
    local target_name = base_target_name
    local target_index = 1
    while used_target_names[target_name] do
        target_name = base_target_name .. "_" .. target_index
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
