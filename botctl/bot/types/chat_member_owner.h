#pragma once
#include <gtest/gtest.h>
#include "chat_member.h"
#include "fields.h"


namespace bot::types {

class ChatMemberOwner : public ChatMember {
public:
    ChatMemberOwner();
    ChatMemberOwner(std::string& json);
    ChatMemberOwner(Value const& value);
    ChatMemberOwner(
        User user, 
        std::string status,
        bool is_anonymous,
        std::string custom_title
    );

    virtual ~ChatMemberOwner() {}

    bool is_anonymous;
    std::string custom_title;


protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};

}