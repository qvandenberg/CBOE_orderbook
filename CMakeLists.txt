##############################################################################
# CMake versioning
##############################################################################
cmake_minimum_required(VERSION 3.16)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

##############################################################################
# Project Options
##############################################################################
project(cboe_data_reader)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_TYPE Debug)

#set(CMAKE_C_COMPILER gcc)
#set(CMAKE_CXX_COMPILER g++)

##############################################################################
# Redirect /build directory output
##############################################################################
# Place all executables in _build/bin folder
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/archive)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

##############################################################################
# Add sources
##############################################################################
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

##############################################################################
# Compile application executables
##############################################################################
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/applications)
