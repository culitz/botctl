#include "callbackquery.h"

namespace bot::types {

CallbackQuery::CallbackQuery() : BaseObject() {}

CallbackQuery::CallbackQuery(string &json) : BaseObject() {
    fromString(json);
}

CallbackQuery::CallbackQuery(const Value &value) : BaseObject() {
    fromNestedObject(value);
}

CallbackQuery::CallbackQuery(
        User &from,
        std::optional<Message> message,
        std::optional<std::string> inline_message_id,
        std::optional<std::string> chat_instance,
        std::optional<std::string> data,
        std::optional<std::string> game_short_name
) : BaseObject(),
    from(from),
    message(message),
    inline_message_id(inline_message_id),
    chat_instance(chat_instance),
    data(data),
    game_short_name(game_short_name)
{}

void CallbackQuery::fillDocument(Writer &writer) const {
    BaseObject::fillDocument(writer);
    writer.Key(fields::FROM);
    from.asNestedObject(writer);

    if(message) {
        writer.Key(fields::MESSAGE);
        message->asNestedObject(writer);
    }

    if(inline_message_id) {
        writer.Key(fields::INLINE_MESSAGE_ID);
        writer.String(inline_message_id->c_str());
    }

    if(chat_instance) {
        writer.Key(fields::CHAT_INSTANCE);
        writer.String(chat_instance->c_str());
    }

    if(data) {
        writer.Key(fields::DATA);
        writer.String(data->c_str());
    }

    if(game_short_name) {
        writer.Key(fields::GAME_SHORT_NAME);
        writer.String(game_short_name->c_str());
    }
}

void CallbackQuery::fillObject(const Value &document) {
    BaseObject::fillObject(document);
    from.fromNestedObject(document[fields::FROM]);

    if(message) {
        Message tmp;
        tmp.fromNestedObject(document[fields::MESSAGE]);
        message.emplace(tmp);
    }

    if(inline_message_id)
        inline_message_id = document[fields::INLINE_MESSAGE_ID].GetString();

    if(chat_instance)
        chat_instance = document[fields::CHAT_INSTANCE].GetString();

    if(data)
        data = document[fields::DATA].GetString();

    if(game_short_name)
        game_short_name = document[fields::GAME_SHORT_NAME].GetString();
}

}
