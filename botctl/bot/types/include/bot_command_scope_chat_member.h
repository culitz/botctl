#pragma once
#include "constants.h"
#include "bot_command_scope_chat_administrators.h"


namespace bot::types {

class BotCommandScopeChatMember : public BotCommandScopeChatAdministrators
{
public:
    typedef BotCommandScopeChatAdministrators Parent;
    BotCommandScopeChatMember();
    BotCommandScopeChatMember(string& json);
    virtual ~BotCommandScopeChatMember() {}

    int user_id;
protected:
    virtual void fillDocument(Writer& writer) const override;
    virtual void fillObject(Value const& document) override;
};

}
