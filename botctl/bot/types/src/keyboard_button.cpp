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
    std::optional<KeyboardButtonPollType> request_poll
) : 
    BaseObject(),
    text(text),
    request_contact(request_contact),
    request_location(request_location),
    request_poll(request_poll) {}

KeyboardButton::~KeyboardButton() {}

void KeyboardButton::fillDocument(Writer& writer) const {
    writer.Key(fields::TEXT);
    writer.String(text.c_str());
    
    if(request_contact) {
        writer.Key(fields::REQUEST_CONTACT);
        writer.Bool(request_contact.value());
    }

    if(request_location) {
        writer.Key(fields::REQUEST_LOCATION);
        writer.Bool(request_location.value());
    }

    if(request_poll) {
        writer.Key(fields::REQUEST_POLL);
        request_poll->asNestedObject(writer);
    }
}

void KeyboardButton::fillObject(Value const& document) {
    text = document[fields::TEXT].GetString();
    request_contact = getOptBool(document, fields::REQUEST_CONTACT);
    request_location = getOptBool(document, fields::REQUEST_LOCATION);
    if(document.HasMember(fields::REQUEST_POLL)) {
        KeyboardButtonPollType poll(document[fields::REQUEST_POLL]);
        request_poll.emplace(poll);
    }
}

}
