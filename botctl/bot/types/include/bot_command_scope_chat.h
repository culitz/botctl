#pragma once
#include "bot_command_scope.h"
#include "constants.h"

namespace bot::types {


class BotCommandScopeChat : public BotCommandScope
{
public:
    BotCommandScopeChat();
    virtual ~BotCommandScopeChat() {}
};

}
