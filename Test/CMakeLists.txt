find_package(GTest REQUIRED)
find_package(glm REQUIRED)

file(GLOB_RECURSE TEST_FILES *.cpp)

add_executable(MkTest ${TEST_FILES})

target_include_directories(MkTest PUBLIC "../Engine/inc")
target_link_libraries(MkTest PRIVATE GTest::GTest GTest::Main glm Engine)

add_test(test MkTest)