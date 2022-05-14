#pragma once
#include "chat_member.h"
#include "fields.h"

namespace bot::types {

class ChatMemberAdministrator : public ChatMember {
public:
    bool                        can_be_edited;
    bool                        is_anonymous;
    bool                        can_manage_chat;
    bool                        can_delete_messages;
    bool                        can_manage_video_chats;
    bool                        can_restrict_members;
    bool                        can_promote_members;
    bool                        can_change_info;
    bool                        can_invite_users;
    std::optional<bool>         can_post_messages;
    std::optional<bool>         can_edit_messages;
    std::optional<bool>         can_pin_messages;
    std::optional<std::string>  custom_title;	

    ChatMemberAdministrator();
    ChatMemberAdministrator(std::string& json);
    ChatMemberAdministrator(Value const& document);
    ChatMemberAdministrator(
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
    );

    virtual ~ChatMemberAdministrator() {}

protected:
    virtual void fillDocument(Writer& writer) const override;
    virtual void fillObject(Value const& document) override;
};

}