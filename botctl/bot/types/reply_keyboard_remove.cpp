#include "reply_keyboard_remove.h"

namespace bot::types {

ReplyKeyboardRemove::ReplyKeyboardRemove() : BaseObject() {}

ReplyKeyboardRemove::ReplyKeyboardRemove(string& json) : BaseObject() {
    fromString(json);
}

ReplyKeyboardRemove::ReplyKeyboardRemove(const Value& value) : BaseObject() {
    fillObject(value);
}

ReplyKeyboardRemove::ReplyKeyboardRemove(
    bool remove_keyboard, 
    std::optional<bool> selective
) : BaseObject(),
    remove_keyboard(remove_keyboard),
    selective(selective) {}

ReplyKeyboardRemove::~ReplyKeyboardRemove() {}


void ReplyKeyboardRemove::fillDocument(Writer& writer) const {
    writer.Key(fields::REMOVE_KEYBOARD);
    writer.Bool(remove_keyboard);

    if(selective) {
        writer.Key(fields::SELECTIVE);
        writer.Bool(selective.value());
    }
}

void ReplyKeyboardRemove::fillObject(Value const& document) {
    remove_keyboard = document[fields::REMOVE_KEYBOARD].GetBool();
    if(document.HasMember(fields::SELECTIVE)) {
        selective = document[fields::SELECTIVE].GetBool();
    }
}

}