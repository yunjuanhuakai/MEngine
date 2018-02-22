cmake_minimum_required(VERSION 2.6)

project(MEngine)

enable_testing()

add_subdirectory("Engine" lib)
add_subdirectory("Test" test)
