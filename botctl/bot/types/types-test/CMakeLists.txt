cmake_minimum_required(VERSION 3.5)

project(types-test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(GTest REQUIRED)


include_directories(${GTEST_INCLUDE_DIRS})
add_executable(
    types_test
    "base_type_test.cpp"
    "chat_type_test.cpp"
    "../base_object.cpp"
    "../chat.cpp"
)

target_link_libraries(types_test GTest::GTest GTest::Main)
add_test(test-1 test1)
