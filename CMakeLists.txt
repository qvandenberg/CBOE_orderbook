# Makes it backwards compatible with previous versions of CMake
cmake_minimum_required(VERSION 3.1...3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(catch2_sample)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
add_subdirectory(src)
add_subdirectory(test)

# or, if you only want tests to compile when you
# want them to, you can do something like this:

# option(BUILD_TESTS "Determines whether to build tests or not" OFF)
# if(${BUILD_TESTS})
#     add_subdirectory(test)
# endif()

# Then run with cmake .. for no tests
# and cmake .. -DBUILD_TESTS=ON for tests
