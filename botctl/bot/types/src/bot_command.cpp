#include "bot_command.h"


namespace bot::types {

BotCommand::BotCommand() : BaseObject() {}

BotCommand::BotCommand(string command, string description) : 
    BaseObject(), command(command), description(description) {

}

BotCommand::BotCommand(string& json) : BaseObject() {
    fromString(json);
}

BotCommand::BotCommand(Value const& value) : BaseObject() {
    fillObject(value);
}

void BotCommand::fillDocument(Writer& writer) const {
    writer.Key(fields::COMMAND);
    writer.String(command.c_str());
    writer.Key(fields::DESCRIPTION);
    writer.String(description.c_str());
}

void BotCommand::fillObject(Value const& document) {
    command = document[fields::COMMAND].GetString();
    description = document[fields::DESCRIPTION].GetString();
}

}
