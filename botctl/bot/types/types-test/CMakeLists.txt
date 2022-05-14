cmake_minimum_required(VERSION 3.5)

project(types-test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SRC "../")
enable_testing()


find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
#add_subdirectory(${SRC})

file(GLOB_RECURSE TESTS "src/*.cpp")
add_executable(types-tests ${TESTS})

target_link_libraries(types-tests GTest::GTest GTest::Main bot-types)
#add_test(test-1 test1)
