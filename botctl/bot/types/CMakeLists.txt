cmake_minimum_required(VERSION 3.5)

project(bot-types LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


enable_testing()

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

file(GLOB_RECURSE SRC_CC "src/*.cpp")

#include_directories(
#    ${GTEST_INCLUDE_DIRS}
#    ${CMAKE_SOURCE_DIR}/include
#    ${GFLAGS_INCLUDE_DIR}
#    ${BENCHMARK_INCLUDE_DIR}
#    ${RAPIDJSON_INCLUDE_DIR}
#)

add_library(bot-types STATIC ${SRC_CC})
target_include_directories(bot-types PUBLIC  ${PROJECT_SOURCE_DIR}/include)
