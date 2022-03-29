#include "keyboard_button.h"


namespace bot::types {

KeyboardButton::KeyboardButton() {}

KeyboardButton::KeyboardButton(string& json) : BaseObject() {
    fromString(json);
}

KeyboardButton::KeyboardButton(const Value& value) : BaseObject() {
    fillObject(value);
}

KeyboardButton::KeyboardButton(
    string& text,
    std::optional<bool> request_contact,
    std::optional<bool> request_location,
    std::optional<BaseObject> request_poll
) : 
    BaseObject(),
    text(text),
    request_contact(request_contact),
    request_location(request_location),
    request_poll(request_poll) {}

KeyboardButton::~KeyboardButton() {}


}