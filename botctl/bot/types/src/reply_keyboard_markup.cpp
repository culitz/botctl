#include "reply_keyboard_markup.h"

namespace bot::types {

ReplyKeyboardMarkup::ReplyKeyboardMarkup() : BaseObject() {}

ReplyKeyboardMarkup::ReplyKeyboardMarkup(string& json) : BaseObject() {
    fromString(json);
}

ReplyKeyboardMarkup::ReplyKeyboardMarkup(const Value&) : BaseObject() {}

ReplyKeyboardMarkup::ReplyKeyboardMarkup(
    std::vector<KeyboardButton>& keyboard,
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
    for(const KeyboardButton btn : keyboard) {
        writer.Key(fields::KEYBOARD);
        btn.asNestedObject(writer);
    }
    if(resize_keyboard) {
        writer.Key(fields::RESIZE_KEYBOARD);
        writer.Bool(resize_keyboard.value());
    }
    if(one_time_keyboard) {
        writer.Key(fields::ONE_TIME_KEYBOARD);
        writer.Bool(one_time_keyboard.value());
    }
    if(input_field_placeholder){
        writer.Key(fields::INPUT_FIELD_PLACEHOLDER);
        writer.String(input_field_placeholder->c_str());
    }
    if(selective) {
        writer.Key(fields::SELECTIVE);
        writer.Bool(selective.value());
    }
}

void ReplyKeyboardMarkup::fillObject(Value const& document) {
    auto array = document[fields::KEYBOARD].GetArray();
    for(const auto& button : array) 
        keyboard.push_back(KeyboardButton(button));
    resize_keyboard = getOptBool( document, fields::RESIZE_KEYBOARD);
    one_time_keyboard = getOptBool(document, fields::ONE_TIME_KEYBOARD);
    input_field_placeholder = getOptString(document, fields::INPUT_FIELD_PLACEHOLDER);
    selective = getOptBool(document, fields::SELECTIVE);
}

}
