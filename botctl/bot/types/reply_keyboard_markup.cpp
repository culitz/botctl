#include "reply_keyboard_markup.h"

namespace bot::types {

ReplyKeyboardMarkup::ReplyKeyboardMarkup() : BaseObject() {}

ReplyKeyboardMarkup::ReplyKeyboardMarkup(string& json) : BaseObject() {
    fromString(json);
}

ReplyKeyboardMarkup::ReplyKeyboardMarkup(const Value&) : BaseObject() {}

ReplyKeyboardMarkup::ReplyKeyboardMarkup(
    std::vector<BaseObject>& keyboard,
    std::optional<bool> resize_keyboard = {},
    std::optional<bool> one_time_keyboard = {},
    std::optional<string> input_field_placeholder = {},
    std::optional<bool> selective = {}
) : 
    BaseObject(), 
    keyboard(keyboard),
    resize_keyboard(resize_keyboard),
    one_time_keyboard(one_time_keyboard),
    input_field_placeholder(input_field_placeholder),
    selective(selective)
    {}

ReplyKeyboardMarkup::~ReplyKeyboardMarkup() {}

void ReplyKeyboardMarkup::fillDocument(Writer& writer) const {

}

void ReplyKeyboardMarkup::fillObject(Value const& document) {
    
}

}