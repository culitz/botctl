#include "bot_command_scope_chat_member.h"


namespace bot::types {

BotCommandScopeChatMember::BotCommandScopeChatMember()
    : BotCommandScopeChatAdministrators()
{
    type = consts::command::scope::CHAT_MEMBER;
}

BotCommandScopeChatMember::BotCommandScopeChatMember(string& json) 
    : BotCommandScopeChatAdministrators() 
{
    fromString(json);
}

void BotCommandScopeChatMember::fillDocument(Writer& writer) const {
    Parent::fillDocument(writer);
    writer.Key(fields::USER_ID);
    writer.Int(user_id);
}

void BotCommandScopeChatMember::fillObject(const Value& document) {
    Parent::fillObject(document);
    user_id = document[fields::USER_ID].GetInt();
}

}
