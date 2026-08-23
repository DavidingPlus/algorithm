add_rules("mode.debug", "mode.release")

set_project("algorithm")
set_version("1.0.0")

-- MSVC 默认按系统代码页读取源文件；仓库源码统一使用 UTF-8。
if is_plat("windows") then
    add_cxxflags("/utf-8")
end

includes("leetcode/cpp-template")
includes("hello-algo")
