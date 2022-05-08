#include "chat_permissions.h"


namespace bot::types {

ChatPermissions::ChatPermissions(
        std::optional<bool> can_send_messages,
        std::optional<bool> can_send_media_messages,
        std::optional<bool> can_send_polls,
        std::optional<bool> can_send_other_messages,
        std::optional<bool> can_add_web_page_previews,
        std::optional<bool> can_change_info,
        std::optional<bool> can_invite_users,
        std::optional<bool> can_pin_messages)
    : BaseObject(),
    can_send_messages(can_send_messages),
    can_send_media_messages(can_send_media_messages),
    can_send_polls(can_send_polls),
    can_send_other_messages(can_send_other_messages),
    can_add_web_page_previews(can_add_web_page_previews),
    can_change_info(can_change_info),
    can_invite_users(can_invite_users),
    can_pin_messages(can_pin_messages) {}

ChatPermissions::ChatPermissions(string &json) : BaseObject() {
    fromString(json);
}

ChatPermissions::ChatPermissions(const Value& value) : BaseObject() {
    fromNestedObject(value);
}

void ChatPermissions::fillDocument(Writer& writer) const {
    if(can_send_messages) {
        writer.Key(fields::CAN_SEND_MESSAGES);
        writer.Bool(*can_send_messages);
    }
    if(can_send_media_messages) {
        writer.Key(fields::CAN_SEND_MEDIA_MESSAGES);
        writer.Bool(*can_send_media_messages);
    }
    if(can_send_polls) {
        writer.Key(fields::CAN_SEND_POLLS);
        writer.Bool(*can_send_polls);
    }
    if(can_send_other_messages) {
        writer.Key(fields::CAN_SEND_OTHER_MESSAGES);
        writer.Bool(*can_send_other_messages);
    }
    if(can_add_web_page_previews) {
        writer.Key(fields::CAN_ADD_WEB_PAGE_PREVIEWS);
        writer.Bool(*can_add_web_page_previews);
    }
    if(can_change_info) {
        writer.Key(fields::CAN_CHANGE_INFO);
        writer.Bool(*can_change_info);
    }
    if(can_invite_users) {
        writer.Key(fields::CAN_INVITE_USERS);
        writer.Bool(*can_invite_users);
    }
    if(can_pin_messages) {
        writer.Key(fields::CAN_PIN_MESSAGES);
        writer.Bool(*can_pin_messages);
    }
}

void ChatPermissions::fillObject(Value const& document) {
    can_send_messages = getOptBool(document, fields::CAN_SEND_MESSAGES);
    can_send_media_messages = getOptBool(
        document, 
        fields::CAN_SEND_MEDIA_MESSAGES
    );
    can_send_polls = getOptBool(document, fields::CAN_SEND_POLLS);
    can_send_other_messages = getOptBool(
        document, fields::CAN_SEND_OTHER_MESSAGES
    );
    can_add_web_page_previews = getOptBool(
        document, 
        fields::CAN_ADD_WEB_PAGE_PREVIEWS
    );
    can_change_info = getOptBool(document, fields::CAN_CHANGE_INFO);
    can_invite_users = getOptBool(document, fields::CAN_INVITE_USERS);
    can_pin_messages = getOptBool(document, fields::CAN_PIN_MESSAGES);
}

}
