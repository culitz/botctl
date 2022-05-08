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
    "poll_type_test.cpp"
    "location_type_test.cpp"
    "venue_type_test.cpp"
    "message_auto_delete_timer_changed.cpp"
    "voice_chat_scheduled_type_test.cpp"
    "voice_chat_participants_invited_type_test.cpp"
    "user_profile_photos_type_test.cpp"  
    "file_type_test.cpp"
    "keyboard_button_type_test.cpp"
    "keyboard_button_poll_type_test.cpp"
    "reply_keyboard_remove_type_test.cpp"
    "callbackquery_test.cpp"
    "force_reply_test.cpp"
    "chat_photo_test.cpp"
    "chat_invite_link_test.cpp"
    "chat_administrator_rights_test"
    "chat_member_test.cpp"
    "chat_member_owner_test.cpp"
    "chat_member_administrator_test.cpp"
    "chat_member_member_test.cpp"
    "chat_member_restricted_test.cpp"
    "chat_member_left_test.cpp"
    "chat_member_banned_test.cpp"
    "chat_member_updated_test.cpp"
    "chat_join_request_test.cpp"
    "chat_permissions_test.cpp"

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
    "../poll.cpp"
    "../location.cpp"
    "../venue.cpp"
    "../message_auto_delete_timer_changed.cpp"
    "../voice_chat_scheduled.cpp"
    "../voice_chat_ended.cpp"
    "../voice_chat_participants_invited.cpp"
    "../user_profile_photos.cpp"
    "../file.cpp"
    "../keyboard_button.cpp"
    "../keyboard_button_poll_type.cpp"
    "../reply_keyboard_remove.cpp"
    "../login_url.cpp"
    "../callbackquery.cpp"
    "../force_reply.cpp"
    "../chat_photo.cpp"
    "../chat_invite_link.cpp"
    "../chat_administrator_rights.cpp"
    "../chat_member.cpp"
    "../chat_member_owner.cpp"
    "../chat_member_administrator.cpp"
    "../chat_member_member.cpp"
    "../chat_member_restricted.cpp"
    "../chat_member_left.cpp"
    "../chat_member_banned.cpp"
    "../chat_member_updated.cpp"
    "../chat_join_request.cpp"
    "../chat_permissions.cpp"
)

target_link_libraries(types_test GTest::GTest GTest::Main)
add_test(test-1 test1)
