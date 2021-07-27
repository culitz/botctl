cmake_minimum_required(VERSION 3.5)

project(botctl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(GTest REQUIRED)


include_directories(${GTEST_INCLUDE_DIRS})
add_subdirectory("botctl/bot/types/types-test")

add_executable(
    cbot
    main.cpp
    "botctl/bot/types/base_object.cpp"
    "botctl/bot/types/chat.cpp"
    "botctl/bot/types/user.cpp"
)

target_link_libraries(cbot pthread)

