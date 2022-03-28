cmake_minimum_required(VERSION 3.5)

project(botctl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

include("${CMAKE_SOURCE_DIR}/third_party/rapid_json.cmake")
# Add source files
file(GLOB_RECURSE SRC_CC "src/*.cc")

include_directories(
    ${GTEST_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include
    ${GFLAGS_INCLUDE_DIR}
    ${BENCHMARK_INCLUDE_DIR}
    ${RAPIDJSON_INCLUDE_DIR}
)

add_subdirectory("botctl/bot/types/types-test")

add_executable(
    cbot
    main.cpp
    "botctl/bot/types/fields.cpp"
    "botctl/bot/types/base_object.cpp"
    "botctl/bot/types/base_file.cpp"
    "botctl/bot/types/chat.cpp"
    "botctl/bot/types/user.cpp"
    "botctl/bot/types/message.cpp"
    "botctl/bot/types/message_id.cpp"
    "botctl/bot/types/message_entity.cpp"
    "botctl/bot/types/photo_size.cpp"
    "botctl/bot/types/animation.cpp"
    "botctl/bot/types/audio.cpp"
    "botctl/bot/types/document.cpp"
    "botctl/bot/types/video.cpp"
    "botctl/bot/types/video_note.cpp"
    "botctl/bot/types/voice.cpp"
    "botctl/bot/types/contact.cpp"
    "botctl/bot/types/dice.cpp"
    "botctl/bot/types/poll_options.cpp"
    "botctl/bot/types/poll_answer.cpp"
    "botctl/bot/types/poll.cpp"
    "botctl/bot/types/location.cpp"
    "botctl/bot/types/venue.cpp"
    "botctl/bot/types/proximity_alert_triggered.cpp"
    "botctl/bot/types/message_auto_delete_timer_changed.cpp"
    "botctl/bot/types/voice_chat_scheduled.cpp"
    "botctl/bot/types/voice_chat_ended.cpp"
    "botctl/bot/types/voice_chat_participants_invited.cpp"
)
target_link_libraries(cbot gflags pthread ${SRC_CC})
add_dependencies(cbot rapidjson)
