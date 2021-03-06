# src-level CMakeLists

cmake_minimum_required(VERSION 3.9 FATAL_ERROR)



# Specify the project, its version and the used language
project(cpputil
        VERSION 1.6.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)



# Set some compiler optimizations (https://stackoverflow.com/a/41361741/7930415)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -march=native")



# Set CMake variables
include(${CMAKE_SOURCE_DIR}/cmake/SetCMakeEnvironment.cmake)



message(STATUS "Building ${LIBRARY_NAME} for ${CMAKE_BUILD_TYPE}")



# Find all required packages. Update CMake's MODULE_PATH to let CMake know that we have supplied our own FindXXX.cmake files in the cmake directory
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
include(${CMAKE_SOURCE_DIR}/cmake/FindPackages.cmake)



# Add the sources for the library
add_subdirectory(${PROJECT_SOURCE_FOLDER})



# Set up testing
enable_testing()
add_subdirectory(${PROJECT_TESTS_FOLDER})
