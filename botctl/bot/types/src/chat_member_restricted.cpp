#include "chat_member_restricted.h"

namespace bot::types {

ChatMemberRestricted::ChatMemberRestricted() : ChatMember() {}

ChatMemberRestricted::ChatMemberRestricted(std::string& json) : ChatMember() {
    fromString(json);
}

ChatMemberRestricted::ChatMemberRestricted(Value const& document) : ChatMember() {
    fromNestedObject(document);
}

ChatMemberRestricted::ChatMemberRestricted(
    User        user,
    std::string status,
    bool        is_member, 
    bool        can_change_info,
    bool        can_invite_users, 
    bool        can_pin_messages, 
    bool        can_send_messages,
    bool        can_send_media_messages, 
    bool        can_send_polls,	
    bool        can_send_other_messages, 
    bool        can_add_web_page_previews, 
    int         until_date
) : ChatMember(user, status),
    is_member(is_member),
    can_change_info(can_change_info),
    can_invite_users(can_invite_users),
    can_pin_messages(can_pin_messages),
    can_send_messages(can_send_messages),
    can_send_media_messages(can_send_media_messages),
    can_send_polls(can_send_polls),
    can_send_other_messages(can_send_other_messages),
    can_add_web_page_previews(can_add_web_page_previews),
    until_date(until_date) {}

void ChatMemberRestricted::fillDocument(Writer& writer) const {
    ChatMember::fillDocument(writer);
    writer.Key(fields::IS_MEMBER);
    writer.Bool(is_member);
    writer.Key(fields::CAN_CHANGE_INFO);
    writer.Bool(can_change_info);
    writer.Key(fields::CAN_INVITE_USERS);
    writer.Bool(can_invite_users);
    writer.Key(fields::CAN_PIN_MESSAGES);
    writer.Bool(can_pin_messages);
    writer.Key(fields::CAN_SEND_MESSAGES);
    writer.Bool(can_send_messages);
    writer.Key(fields::CAN_SEND_MEDIA_MESSAGES);
    writer.Bool(can_send_media_messages);
    writer.Key(fields::CAN_SEND_POLLS);
    writer.Bool(can_send_polls);
    writer.Key(fields::CAN_SEND_OTHER_MESSAGES);
    writer.Bool(can_send_other_messages);
    writer.Key(fields::CAN_ADD_WEB_PAGE_PREVIEWS);
    writer.Bool(can_add_web_page_previews);
    writer.Key(fields::UNTIL_DATE);
    writer.Int(until_date);
}

void ChatMemberRestricted::fillObject(Value const& document) {
    ChatMember::fillObject(document);
    is_member = document[fields::IS_MEMBER].GetBool();
    can_change_info = document[fields::CAN_CHANGE_INFO].GetBool();
    can_invite_users = document[fields::CAN_INVITE_USERS].GetBool();
    can_pin_messages = document[fields::CAN_PIN_MESSAGES].GetBool();
    can_send_messages = document[fields::CAN_SEND_MESSAGES].GetBool();
    can_send_media_messages = document[fields::CAN_SEND_MEDIA_MESSAGES].GetBool();
    can_send_polls = document[fields::CAN_SEND_POLLS].GetBool();
    can_send_other_messages = document[fields::CAN_SEND_OTHER_MESSAGES].GetBool();
    can_add_web_page_previews = document[fields::CAN_ADD_WEB_PAGE_PREVIEWS].GetBool();
    until_date = document[fields::UNTIL_DATE].GetInt();
}

}
