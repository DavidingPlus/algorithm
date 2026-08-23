-- The CMake target contains headers only, so represent it as a non-linking
-- target while keeping the same files visible to XMake project generators.
target("utils")
    set_kind("phony")
    add_headerfiles("common.hpp", "list_node.hpp", "print_utils.hpp", "tree_node.hpp", "vertex.hpp", {install = false})
