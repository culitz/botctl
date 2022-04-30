#pragma once
#include "chat_member.h"
#include "fields.h"

namespace bot::types {

class ChatMemberRestricted : public ChatMember {
public:
    bool is_member; 
    bool can_change_info;
    bool can_invite_users; 
    bool can_pin_messages; 
    bool can_send_messages;
    bool can_send_media_messages; 
    bool can_send_polls;	
    bool can_send_other_messages; 
    bool can_add_web_page_previews; 
    int until_date;

    ChatMemberRestricted();
    ChatMemberRestricted(std::string& json);
    ChatMemberRestricted(Value const& document);
    ChatMemberRestricted(
        User user,
        std::string status,
        bool is_member, 
        bool can_change_info,
        bool can_invite_users, 
        bool can_pin_messages, 
        bool can_send_messages,
        bool can_send_media_messages, 
        bool can_send_polls,	
        bool can_send_other_messages, 
        bool can_add_web_page_previews, 
        int until_date
    );

    virtual ~ChatMemberRestricted() {}

protected:
    virtual void fillDocument(Writer& writer) const override;
    virtual void fillObject(Value const& document) override;
};

}