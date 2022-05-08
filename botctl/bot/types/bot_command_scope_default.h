#pragma once
#include "bot_command_scope.h"
#include "constants.h"


namespace bot::types {

class BotCommandScopeDefault : public BotCommandScope {
public:
    BotCommandScopeDefault();
    virtual ~BotCommandScopeDefault() {}
};

}