#pragma once
#include "bot_command_scope.h"
#include "constants.h"

namespace bot::types {

class BotCommandScopeAllPrivateChats : public BotCommandScope{
public:
    BotCommandScopeAllPrivateChats();
    virtual ~BotCommandScopeAllPrivateChats() {}
};

}
