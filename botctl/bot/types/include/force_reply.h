#pragma once
#include "base_object.h"
#include "fields.h"

namespace bot::types {

/**
 * @brief Upon receiving a message with this object, Telegram clients will display
 * a reply interface to the user (act as if the user has selected the bot's message
 * and tapped 'Reply'). This can be extremely useful if you want to create
 * user-friendly step-by-step interfaces without having to sacrifice privacy mode.
 */
class ForceReply : public BaseObject
{
public:
    ForceReply();
    ForceReply(std::string& json);
    ForceReply(const Value& document);
    ForceReply(
            bool force_reply,
            std::optional<std::string> input_field_placeholder = {},
            std::optional<bool> selective = {}
    );
    virtual ~ForceReply();

    /**
     * @brief Shows reply interface to the user, as if they
     * manually selected the bot's message and tapped 'Reply'
     */
    bool force_reply;
    /**
     * @brief Optional. The placeholder to be shown in the input
     * field when the reply is active; 1-64 characters
     */
    std::optional<std::string> input_field_placeholder;
    /**
     * @brief Optional. Use this parameter if you want to
     * force reply from specific users only.
     * Targets:
     * 1) users that are @mentioned in the text of the Message object;
     * 2) if the bot's message is a reply (has reply_to_message_id), sender
     *    of the original message.
     */
    std::optional<bool> selective;

protected:
    virtual void fillDocument(Writer& writer) const override;
    virtual void fillObject(Value const& document) override;
};

}
