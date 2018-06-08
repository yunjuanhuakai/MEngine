cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

project(MEngine)

enable_testing()

add_subdirectory("Engine" lib)
add_subdirectory("Test" test)
