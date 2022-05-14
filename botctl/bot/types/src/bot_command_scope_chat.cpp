#include "bot_command_scope_chat.h"


namespace bot::types {

BotCommandScopeChat::BotCommandScopeChat() : BotCommandScope() {
    type = consts::command::scope::CHAT;
}

}
