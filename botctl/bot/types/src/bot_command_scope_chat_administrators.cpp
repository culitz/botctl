#include "bot_command_scope_chat_administrators.h"

namespace bot::types {

BotCommandScopeChatAdministrators::BotCommandScopeChatAdministrators() : BotCommandScope() {
    type = consts::command::scope::CHAT_ADMINISTRATORS;
}

BotCommandScopeChatAdministrators::BotCommandScopeChatAdministrators(const Value& value) {
    fillObject(value);
}

void BotCommandScopeChatAdministrators::fillDocument(Writer& writer) const {
    Parent::fillDocument(writer);
    if(chat_id || chat_sup_username) {
        writer.Key(fields::CHAT_ID);
        if(chat_sup_username)
            writer.String(chat_sup_username->c_str());
        else if(chat_id)
            writer.Int(*chat_id);
    }
}

void BotCommandScopeChatAdministrators::fillObject(const Value& document) {
    Parent::fillObject(document);
    bool flag = document.HasMember(fields::CHAT_ID);
    if(document.HasMember(fields::CHAT_ID)) {
        auto& field = document[fields::CHAT_ID];
        if(field.IsString())
            chat_sup_username = field.GetString();

        else if(field.IsInt())
            chat_id = field.GetInt();
    }
}

}
