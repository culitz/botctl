#pragma once
#include "base_object.h"
#include "user.h"
#include "message.h"
#include "fields.h"

namespace bot::types {

/**
 * @brief This object represents an incoming callback query from a callback button
 * in an inline keyboard. If the button that originated the query was attached
 * to a message sent by the bot, the field message will be present. If the button
 * was attached to a message sent via the bot (in inline mode), the field
 * inline_message_id will be present. Exactly one of the fields data or
 * game_short_name will be present.
 */
class CallbackQuery : public BaseObject
{
public:
    /**
     * @brief CallbackQuery default constructor
     */
    CallbackQuery();
    /**
     * @brief CallbackQuery constructor from json string
     * @param json - json string
     */
    CallbackQuery(string& json);
    /**
     * @brief CallbackQuery constructor from json parsed object
     * @param value - parsed json object
     */
    CallbackQuery(const Value& value);
    CallbackQuery(
            User& user,
            std::optional<Message> message = {},
            std::optional<std::string> inline_message_id = {},
            std::optional<std::string> chat_instance = {},
            std::optional<std::string> data = {},
            std::optional<std::string> game_short_name = {}
    );
    virtual ~CallbackQuery() {}

    /**
     * @brief Sender
     */
    User from;
    /**
     * @brief Optional. Message with the callback button that originated the query.
     * Note that message content and message date will not be available if the
     * message is too old
     */
    std::optional<Message> message;
    /**
     * @brief Optional. Identifier of the message sent via the bot in inline mode,
     * that originated the query.
     */
    std::optional<std::string> inline_message_id;
    /**
     * @brief Global identifier, uniquely corresponding to the chat to which the
     * message with the callback button was sent. Useful for high scores in games.
     */
    std::optional<std::string> chat_instance;
    /**
     * @brief Optional. Data associated with the callback button. Be aware that
     * a bad client can send arbitrary data in this field.
     */
    std::optional<std::string> data;
    /**
     * @brief Optional. Short name of a Game to be returned, serves as the unique
     * identifier for the game
     */
    std::optional<std::string> game_short_name;

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};

}
