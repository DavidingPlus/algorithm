# Get a list of directories with a CMakeLists.txt inside
file (GLOB ITEMS RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/*)
set (SUB_DIRS "")
foreach (ITEM ${ITEMS})
    if (
        IS_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/${ITEM} 
        AND EXISTS ${CMAKE_CURRENT_LIST_DIR}/${ITEM}/CMakeLists.txt
        AND EXISTS ${CMAKE_CURRENT_LIST_DIR}/${ITEM}/.buildme
    )
        list (APPEND SUB_DIRS ${ITEM})
    endif()
endforeach()

get_property (PROP_GENERATOR_IS_MULTI_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
message ("-- Multi-config generator flag: ${PROP_GENERATOR_IS_MULTI_CONFIG}")


# Run add_subdirectory() for each
foreach (SUB_DIR ${SUB_DIRS})
    add_subdirectory (${SUB_DIR})
endforeach()

unset (PROP_GENERATOR_IS_MULTI_CONFIG)

message ("-- Done configuring buaa")
