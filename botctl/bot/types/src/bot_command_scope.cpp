#include "bot_command_scope.h"


namespace bot::types {


BotCommandScope::BotCommandScope() : BaseObject() {

}

BotCommandScope::BotCommandScope(string& json) : BaseObject() {
    fromString(json);
}

BotCommandScope::BotCommandScope(Value const& value) : BaseObject() {
    fillObject(value);
}

void BotCommandScope::fillDocument(Writer& writer) const {
    writer.Key(fields::TYPE);
    writer.String(type.c_str());
}

void BotCommandScope::fillObject(Value const& document) {
    type = document[fields::TYPE].GetString();
}

}
