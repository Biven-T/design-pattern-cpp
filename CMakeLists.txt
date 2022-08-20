cmake_minimum_required(VERSION 3.10)
project(design-pattrtn-cpp)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_subdirectory(creational)