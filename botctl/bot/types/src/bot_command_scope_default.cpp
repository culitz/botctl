#include "bot_command_scope_default.h"


namespace bot::types {

BotCommandScopeDefault::BotCommandScopeDefault() : BotCommandScope() {
    type = consts::command::scope::DEFAULT;
}

}
