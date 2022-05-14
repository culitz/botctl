#pragma once
#include "base_object.h"
#include "user.h"
#include "fields.h"


namespace bot::types {

class ChatMember : public BaseObject {
public:
    ChatMember();
    ChatMember(std::string& json);
    ChatMember(Value const& document);
    ChatMember(User user, std::string status);

    virtual ~ChatMember();

    User user;
    std::string status;

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};

}