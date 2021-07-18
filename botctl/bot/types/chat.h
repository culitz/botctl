#pragma once

#include "base_object.h"
#include <vector>

namespace bot::types {

/// This object represents a Telegram user or bot.
class Chat : public BaseObject
{
private:
    typedef BaseObject Parent;

public:
    inline static const string TYPE {"type"};
    inline static const string TITLE {"title"};
    inline static const string USERNAME {"username"};
    inline static const string FIRSTNAME {"first_name"};
    inline static const string LASTNAME {"last_name"};
    inline static const string PHOTO {"photo"};
    inline static const string BIO {"bio"};
    inline static const string DESCRIPTION {"description"};
    inline static const string INVITE_LINK {"invite_link"};
    inline static const string PINNED_MESSAGE {"pinned_message"};
    inline static const string PERMISSIONS {"permissions"};
    inline static const string SLOW_MODE_DELAY {"slow_mode_delay"};
    inline static const string MESSAGE_AUTO_DELETE_TIME {"message_auto_delete_time"};
    inline static const string STICKER_SET_NAME {"sticker_set_name"};
    inline static const string CAN_SET_STICKER_SET {"can_set_sticker_set"};
    inline static const string LINKED_CHAT_ID {"linked_chat_id"};
    inline static const string LOCATION {"location"};

    Chat();
    Chat( ptree& pt );
    ~Chat() {}

    void fromPtree(const ptree&) override;

    string getType() const;
    void setType(const string& type);

    std::optional<string> getTitle() const;
    void setTitle(const string title);

    std::optional<string> getUsername() const;
    void setUsername(const string username);

    std::optional<string> getFirstName() const;
    void setFirstName(const string firstName);

    std::optional<string> getLastName() const;
    void setLastName(const string value);

    std::optional<BaseObject> getPhoto() const;
    void setPhoto(const BaseObject& photo);

    std::optional<string> getBio() const;
    void setBio(const string bio);

    std::optional<string> getDescription() const;
    void setDescription(const string description);

    std::optional<string> getInviteLink() const;
    void setInviteLink(const string inviteLink);

    std::optional<BaseObject> getPinnedMessage() const;
    void setPinnedMessage(const BaseObject& value);

    std::optional<BaseObject> getPermissions() const;
    void setPermissions(const BaseObject& permissions);

    std::optional<int> getSlowModeDelay() const;
    void setSlowModeDelay(const int slowModeDelay);

    std::optional<int> getMessageAutoDeleteTime() const;
    void setMessageAutoDeleteTime(const int messageAutoDeleteTime);

    std::optional<string> getStickerSetName() const;
    void setStickerSetName(const string stickerSetName);

    std::optional<bool> getCanSetStickerSet() const;
    void setCanSetStickerSet(const bool canSetStickerSet);

    std::optional<int> getLinkedChatId() const;
    void setLinkedChatId(const int linkedChatId);

    std::optional<BaseObject> getLocation() const;
    void setLocation(const BaseObject& location);
};

}
