target("hash_map")
    set_kind("binary")
    add_files("hash_map.cpp")

target("array_hash_map_test")
    set_kind("binary")
    add_files("array_hash_map_test.cpp")

target("hash_map_chaining")
    set_kind("binary")
    add_files("hash_map_chaining.cpp")

target("hash_map_open_addressing")
    set_kind("binary")
    add_files("hash_map_open_addressing.cpp")

target("simple_hash")
    set_kind("binary")
    add_files("simple_hash.cpp")

target("built_in_hash")
    set_kind("binary")
    add_files("built_in_hash.cpp")
