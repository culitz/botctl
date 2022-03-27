cmake_minimum_required(VERSION 3.5)

project(types-test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

include_directories(
    ${GTEST_INCLUDE_DIRS}
)
add_executable(
    types_test
    "base_type_test.cpp"
    "base_file_test.cpp"
    "chat_type_test.cpp"
    "user_type_test.cpp"
    "message_type_test.cpp"
    "message_id_type_test.cpp"
    "message_entity_type_test.cpp"
    "photo_size_test.cpp"
    "animation_test.cpp"
    "audio_type_test.cpp"
    "document_type_test.cpp"
    "video_type_test.cpp"
    "video_note_test.cpp"
    "voice_type_test.cpp"
    "contact_type_test.cpp"
    "dice_type_test.cpp"
    "pool_options_type_test.cpp"
    "pool_answer_type_test.cpp"

    "../fields.cpp"
    "../base_object.cpp"
    "../base_file.cpp"
    "../chat.cpp"
    # "../user.cpp"
    "../message.cpp"
    "../message_id.cpp"
    "../message_entity.cpp"
    "../photo_size.cpp"
    "../animation.cpp"
    "../audio.cpp"
    "../document.cpp"
    "../video.cpp"
    "../voice.cpp"
    "../contact.cpp"
    "../dice.cpp"
    "../poll_options.cpp"
    "../poll_answer.cpp"
)

target_link_libraries(types_test GTest::GTest GTest::Main)
add_test(test-1 test1)
