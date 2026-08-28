-- LeetCode C++ 工程的 XMake 入口。
-- 路径相对于 leetcode/cpp 目录：common 是公共代码，cn/en 是两种语言的题解。
-- 每个题解生成一个独立可执行目标，并链接 common 公共静态库。

-- 公共数据结构和辅助代码只编译一次，生成静态库 common。
-- 测试程序位于 common/tests，不编入公共库，避免其中的 main 影响其他目标。
local common_library_sources = os.files("leetcode/editor/common/*.cpp")
local common_test_sources = os.files("leetcode/editor/common/tests/*_test.cpp")

target("common")
    set_kind("static")
    set_languages("c++17")
    add_files(common_library_sources)

-- 为每个公共数据结构注册一个独立测试目标。
for _, source_file in ipairs(common_test_sources) do
    local test_name = path.basename(source_file)
    target(test_name)
        set_kind("binary")
        set_languages("c++17")
        add_files(source_file)
        add_deps("common")
end

-- 记录已经使用过的目标名，避免中英文目录中的同名题解产生冲突。
local used_target_names = {}

local function normalize_target_name(name)
    -- XMake 的 target 名用于终端命令，空白字符统一替换为下划线。
    return (name:gsub("%s+", "_"))
end

local function add_solution(source_file, language)
    local source_name = path.basename(source_file)
    local output_name = source_name .. "_" .. language

    -- 使用“题解文件名_语言”作为目标名，并将其中的空白替换为下划线，
    -- 方便通过 xmake run 补全选择题目；源文件名和输出文件名保持不变。
    local target_name = normalize_target_name(output_name)
    local target_index = 1
    while used_target_names[target_name] do
        target_name = normalize_target_name(output_name) .. "_" .. target_index
        target_index = target_index + 1
    end
    used_target_names[target_name] = true

    target(target_name)
        set_kind("binary")
        set_languages("c++17")
        -- 目标冲突时只调整 XMake 内部目标名，输出文件仍使用原始名称。
        set_basename(output_name)
        add_files(source_file)
        add_deps("common")
end

-- 扫描指定语言目录，为每个题解文件创建目标。
local function add_solutions(language)
    local source_files = os.files("leetcode/editor/" .. language .. "/*.cpp")
    -- 排序保证目标注册顺序稳定，便于查看构建输出和定位问题。
    table.sort(source_files)
    for _, source_file in ipairs(source_files) do
        add_solution(source_file, language)
    end
end

-- 注册中文和英文题解目录。
add_solutions("cn")
add_solutions("en")
