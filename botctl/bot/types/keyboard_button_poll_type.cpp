#include "keyboard_button_poll_type.h"


namespace bot::types {

KeyboardButtonPollType::KeyboardButtonPollType() : BaseObject() {}

KeyboardButtonPollType::KeyboardButtonPollType(string& json) : BaseObject() {
    fromString(json);
}

KeyboardButtonPollType::KeyboardButtonPollType(const Value& value) : BaseObject() {
    fillObject(value);
}

KeyboardButtonPollType::~KeyboardButtonPollType() {}

void KeyboardButtonPollType::fillDocument(Writer& writer) const {
    if(type) {
        writer.Key(fields::TYPE);
        writer.String(type->c_str());
    }
}

void KeyboardButtonPollType::fillObject(Value const& document) {
    if(document.HasMember(fields::TYPE)){
        type = document[fields::TYPE].GetString();
    }
}
}