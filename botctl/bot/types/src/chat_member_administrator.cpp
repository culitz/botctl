#include "chat_member_administrator.h"

namespace bot::types {

ChatMemberAdministrator::ChatMemberAdministrator() : ChatMember() {

}

ChatMemberAdministrator::ChatMemberAdministrator(std::string& json) {
    fromString(json);
}

ChatMemberAdministrator::ChatMemberAdministrator(Value const& document) {
    fromNestedObject(document);
}

ChatMemberAdministrator::ChatMemberAdministrator(
    User user, 
    std::string status,
    bool can_be_edited,
    bool is_anonymous,
    bool can_manage_chat,
    bool can_delete_messages,
    bool can_manage_video_chats,
    bool can_restrict_members,
    bool can_promote_members,
    bool can_change_info,
    bool can_invite_users,
    std::optional<bool> can_post_messages,
    std::optional<bool> can_edit_messages,
    std::optional<bool> can_pin_messages,
    std::optional<std::string> custom_title
) : ChatMember(user, status),
    can_be_edited(can_be_edited),
    is_anonymous(is_anonymous),
    can_manage_chat(can_manage_chat),
    can_delete_messages(can_delete_messages),
    can_manage_video_chats(can_manage_video_chats),
    can_restrict_members(can_restrict_members),
    can_promote_members(can_promote_members),
    can_change_info(can_change_info),
    can_invite_users(can_invite_users),
    can_post_messages(can_post_messages),
    can_edit_messages(can_edit_messages),
    can_pin_messages(can_pin_messages),
    custom_title(custom_title) {

}

void ChatMemberAdministrator::fillDocument(Writer& writer) const {
    ChatMember::fillDocument(writer);
    writer.Key(fields::CAN_BE_EDITED);
    writer.Bool(can_be_edited);

    writer.Key(fields::IS_ANONYMOUS);
    writer.Bool(is_anonymous);

    writer.Key(fields::CAN_MANAGE_CHAT);
    writer.Bool(can_manage_chat);

    writer.Key(fields::CAN_DELETE_MESSAGES);
    writer.Bool(can_delete_messages);

    writer.Key(fields::CAN_MANAGE_VIDEO_CHATS);
    writer.Bool(can_manage_video_chats);

    writer.Key(fields::CAN_RESTRICT_MEMBERS);
    writer.Bool(can_restrict_members);

    writer.Key(fields::CAN_PROMOTE_MEMBERS);
    writer.Bool(can_promote_members);

    writer.Key(fields::CAN_CHANGE_INFO);
    writer.Bool(can_change_info);

    writer.Key(fields::CAN_INVITE_USERS);
    writer.Bool(can_invite_users);

    if(can_post_messages) {
        writer.Key(fields::CAN_POST_MESSAGES);
        writer.Bool(*can_post_messages);
    }
    if(can_edit_messages){
        writer.Key(fields::CAN_EDIT_MESSAGES);
        writer.Bool(*can_edit_messages);
    }
    if(can_pin_messages){
        writer.Key(fields::CAN_PIN_MESSAGES);
        writer.Bool(*can_pin_messages);
    }
    if(custom_title) {
        writer.Key(fields::CUSTOM_TITLE);
        writer.String(custom_title->c_str());
    }

}

void ChatMemberAdministrator::fillObject(Value const& document) {
    ChatMember::fillObject(document);
    can_be_edited = document[fields::CAN_BE_EDITED].GetBool();
    is_anonymous = document[fields::IS_ANONYMOUS].GetBool();
    can_manage_chat = document[fields::CAN_MANAGE_CHAT].GetBool();
    can_delete_messages = document[fields::CAN_DELETE_MESSAGES].GetBool();
    can_manage_video_chats = document[fields::CAN_MANAGE_VIDEO_CHATS].GetBool();
    can_restrict_members = document[fields::CAN_RESTRICT_MEMBERS].GetBool();
    can_promote_members = document[fields::CAN_PROMOTE_MEMBERS].GetBool();
    can_change_info = document[fields::CAN_CHANGE_INFO].GetBool();
    can_invite_users = document[fields::CAN_INVITE_USERS].GetBool();
    can_post_messages = getOptBool(document, fields::CAN_POST_MESSAGES);
    can_edit_messages = getOptBool(document, fields::CAN_EDIT_MESSAGES);
    can_pin_messages = getOptBool(document, fields::CAN_PIN_MESSAGES);
    custom_title = getOptString(document, fields::CUSTOM_TITLE);
}

}
