#pragma once
#include <vector>
#include "base_object.h"
#include "fields.h"
#include "keyboard_button.h"

namespace bot::types {

class ReplyKeyboardMarkup : public BaseObject {
public:
    std::vector<KeyboardButton> keyboard;
    std::optional<bool> resize_keyboard;
    std::optional<bool> one_time_keyboard;
    std::optional<string> input_field_placeholder;
    std::optional<bool> selective;

    ReplyKeyboardMarkup();
    ReplyKeyboardMarkup(string&);
    ReplyKeyboardMarkup(const Value&);
    ReplyKeyboardMarkup(
        std::vector<KeyboardButton>& keyboard,
        std::optional<bool> resize_keyboard,
        std::optional<bool> one_time_keyboard,
        std::optional<string> input_field_placeholder,
        std::optional<bool> selective
    );

    virtual ~ReplyKeyboardMarkup();

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};

}