find_package(GTest REQUIRED)
find_package(glm REQUIRED)

file(GLOB_RECURSE TEST_FILES *.cpp) 

add_executable (Test ${TEST_FILES})

target_include_directories(Test PUBLIC "../Engine/inc")
target_link_libraries(Test PRIVATE GTest::GTest GTest::Main glm Engine)

add_test(name test command Test)