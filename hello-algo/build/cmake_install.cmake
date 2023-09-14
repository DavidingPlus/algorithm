# Install script for directory: /home/lzx0626/DavidingPlus/Cpp/为了工作/Algorithm/hello-algo

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/lzx0626/DavidingPlus/Cpp/为了工作/Algorithm/hello-algo/build/chapter_computational_complexity/cmake_install.cmake")
  include("/home/lzx0626/DavidingPlus/Cpp/为了工作/Algorithm/hello-algo/build/chapter_array_and_linkedlist/cmake_install.cmake")
  include("/home/lzx0626/DavidingPlus/Cpp/为了工作/Algorithm/hello-algo/build/chapter_stack_and_queue/cmake_install.cmake")
  include("/home/lzx0626/DavidingPlus/Cpp/为了工作/Algorithm/hello-algo/build/chapter_hashing/cmake_install.cmake")
  include("/home/lzx0626/DavidingPlus/Cpp/为了工作/Algorithm/hello-algo/build/chapter_tree/cmake_install.cmake")
  include("/home/lzx0626/DavidingPlus/Cpp/为了工作/Algorithm/hello-algo/build/chapter_heap/cmake_install.cmake")
  include("/home/lzx0626/DavidingPlus/Cpp/为了工作/Algorithm/hello-algo/build/chapter_graph/cmake_install.cmake")
  include("/home/lzx0626/DavidingPlus/Cpp/为了工作/Algorithm/hello-algo/build/chapter_searching/cmake_install.cmake")
  include("/home/lzx0626/DavidingPlus/Cpp/为了工作/Algorithm/hello-algo/build/chapter_sorting/cmake_install.cmake")
  include("/home/lzx0626/DavidingPlus/Cpp/为了工作/Algorithm/hello-algo/build/chapter_divide_and_conquer/cmake_install.cmake")
  include("/home/lzx0626/DavidingPlus/Cpp/为了工作/Algorithm/hello-algo/build/chapter_backtracking/cmake_install.cmake")
  include("/home/lzx0626/DavidingPlus/Cpp/为了工作/Algorithm/hello-algo/build/chapter_dynamic_programming/cmake_install.cmake")
  include("/home/lzx0626/DavidingPlus/Cpp/为了工作/Algorithm/hello-algo/build/chapter_greedy/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/lzx0626/DavidingPlus/Cpp/为了工作/Algorithm/hello-algo/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
