#include "bot_command_scope_all_chat_administrators.h"


namespace bot::types {

BotCommandScopeAllChatAdministrators
::BotCommandScopeAllChatAdministrators() : BotCommandScope() {
    type = consts::command::scope::ALL_CHAT_ADMINISTRATORS;
}

}
