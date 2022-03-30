#include "inline_keyboard_button.h"

namespace bot::types {


InlineKeyboardButton::InlineKeyboardButton() : BaseObject() {}

InlineKeyboardButton::InlineKeyboardButton(string& json) : BaseObject() {
    fromString(json);
}

InlineKeyboardButton::InlineKeyboardButton(const Value& value) : BaseObject() {
    fillObject(value);
}

InlineKeyboardButton::~InlineKeyboardButton() {}

void InlineKeyboardButton::fillDocument(Writer& writer) const {
    writer.Key(fields::TEXT);
    writer.String(text.c_str());

    writer.Key(fields::URL);
    writer.String(url.c_str());

    if(login_url) {
        writer.Key(fields::LOGIN_URL);
        /// @todo change on LoginUrl
        BaseObject b;
        b.asNestedObject(writer);
    }

    if(callback_data) {
        writer.Key(fields::CALLBACK_DATA);
        writer.String(callback_data->c_str());
    }

    if(switch_inline_query) {
        writer.Key(fields::SWITCH_INLINE_QUERY);
        writer.String(switch_inline_query->c_str());
    }

    if(callback_game) {
        writer.Key(fields::CALLBACK_GAME);
        BaseObject b;
        b.asNestedObject(writer);
    }

    
}

void InlineKeyboardButton::fillObject(Value const& document) {

}



}