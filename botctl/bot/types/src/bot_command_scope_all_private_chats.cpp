#include "bot_command_scope_all_private_chats.h"

namespace bot::types {

BotCommandScopeAllPrivateChats::BotCommandScopeAllPrivateChats()
    : BotCommandScope() {
    type = consts::command::scope::ALL_PRIVATE_CHATS;
}

}
