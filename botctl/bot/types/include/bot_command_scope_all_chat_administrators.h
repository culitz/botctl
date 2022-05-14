#pragma once
#include "bot_command_scope.h"
#include "constants.h"

namespace bot::types {

class BotCommandScopeAllChatAdministrators : public BotCommandScope {
public:
    BotCommandScopeAllChatAdministrators();
    virtual ~BotCommandScopeAllChatAdministrators() {}
};

}
