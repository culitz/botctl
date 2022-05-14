#pragma once
#include "bot_command_scope.h"
#include "constants.h"
#include "fields.h"

namespace bot::types {

class BotCommandScopeChatAdministrators : public BotCommandScope
{
public:
    typedef BotCommandScope Parent;
    BotCommandScopeChatAdministrators();
    BotCommandScopeChatAdministrators(Value const&);
    virtual ~BotCommandScopeChatAdministrators() {}

    std::optional<int> chat_id;
    std::optional<string> chat_sup_username;

protected:
    virtual void fillDocument(Writer& writer) const override;
    virtual void fillObject(Value const& document) override;
};

}
