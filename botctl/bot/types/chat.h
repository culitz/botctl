#pragma once

#include "base_object.h"
#include <vector>
#include "rapidjson/pointer.h"
#include "fields.h"

namespace bot::types {

/// This object represents a Telegram user or bot.
class Chat : public BaseObject
{
public:
    inline static const string TYPE {"type"};
    inline static const string TITLE {"title"};
    inline static const string USERNAME {"username"};
    inline static const string FIRSTNAME {"first_name"};
    inline static const string LASTNAME {"last_name"};
    inline static const string PHOTO {"photo"};
    inline static const string BIO {"bio"};
    inline static const string HAS_PRIVATE_FORWARDS{"has_private_forwards"};
    inline static const string DESCRIPTION {"description"};
    inline static const string INVITE_LINK {"invite_link"};
    inline static const string PINNED_MESSAGE {"pinned_message"};
    inline static const string PERMISSIONS {"permissions"};
    inline static const string SLOW_MODE_DELAY {"slow_mode_delay"};
    inline static const string MESSAGE_AUTO_DELETE_TIME {"message_auto_delete_time"};
    inline static const string HAS_PROTRCTED_CONTENT{"has_protected_content"};
    inline static const string STICKER_SET_NAME {"sticker_set_name"};
    inline static const string CAN_SET_STICKER_SET {"can_set_sticker_set"};
    inline static const string LINKED_CHAT_ID {"linked_chat_id"};
    inline static const string LOCATION {"location"};

    Chat(string& json);
    Chat(Value const&);
    Chat(
        std::optional<string>           type = {},
        std::optional<string>           title = {},
        std::optional<string>           username = {},
        std::optional<string>           first_name = {},
        std::optional<string>           last_name = {},
        std::optional<BaseObject>       photo = {},
        std::optional<string>           bio = {},
        std::optional<bool>             has_private_forwards = {},
        std::optional<string>           description = {},
        std::optional<string>           invite_link = {},
        std::optional<BaseObject>       pinned_message = {},
        std::optional<BaseObject>       permissions = {},
        std::optional<int>              slow_mode_delay = {},
        std::optional<int>              message_auto_delete_time = {},
        std::optional<bool>             has_protected_content = {},
        std::optional<string>           sticker_set_name = {},
        std::optional<bool>             can_set_sticker_set = {},
        std::optional<int>              linked_chat_id = {},
        std::optional<BaseObject>       location = {}
    );
    virtual ~Chat() {}

    std::optional<string> type;
    std::optional<string> title;
    std::optional<string> username;
    std::optional<string> first_name;
    std::optional<string> last_name;
    /// @todo change to PhotoObject type
    std::optional<BaseObject> photo;
    std::optional<string> bio;
    std::optional<bool> has_private_forwards;
    std::optional<string> description;
    std::optional<string> invite_link;
    /// @todo change to message type
    std::optional<BaseObject> pinned_message;
    /// @todo: change to Permission type
    std::optional<BaseObject> permissions;
    std::optional<int> slow_mode_delay;
    std::optional<int> message_auto_delete_time;
    std::optional<bool> has_protected_content;
    std::optional<string> sticker_set_name;
    std::optional<bool> can_set_sticker_set;
    std::optional<int> linked_chat_id;
    /// @todo change to ChatLocation object
    std::optional<BaseObject> location;

    virtual size_t hash() const override;
protected:
    virtual void fillObject(Value const& document) override;
    virtual void fillDocument(Writer &writer) const override;
private:
    typedef BaseObject Parent;
};

}
