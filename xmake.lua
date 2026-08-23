set_project("algorithm")
set_version("0.1.0")

-- XMake has a cross-platform local compilation cache enabled by default.
-- Keep both CMake and XMake builds under the same project root.

includes("leetcode/cpp")
includes("hello-algo")
