cmake_minimum_required (VERSION 3.8)
project (AutonomousDrivingProject)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(config/rplidar.cmake)
include(config/gtest.cmake)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(doc)
