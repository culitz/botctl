#pragma once
#include "base_object.h"
#include "keyboard_button_poll_type.h"
#include "fields.h"


namespace bot::types {

class KeyboardButton : public BaseObject {
public:
    string text;
    std::optional<bool> request_contact;
    std::optional<bool> request_location;
    std::optional<KeyboardButtonPollType> request_poll;

    KeyboardButton();
    KeyboardButton(string&);
    KeyboardButton(const Value&);
    KeyboardButton(
        string& text,
        std::optional<bool> request_contact,
        std::optional<bool> request_location,
        std::optional<KeyboardButtonPollType> request_poll
    );

    virtual ~KeyboardButton();
protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};


}