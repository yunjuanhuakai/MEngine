find_package(glm REQUIRED)

file(GLOB_RECURSE SOURCE_FILES inc/*.h src/*.cpp) 

add_library(Engine ${SOURCE_FILES})

target_include_directories(Engine PUBLIC "inc")
target_link_libraries(Engine PRIVATE glm)