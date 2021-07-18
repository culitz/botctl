#include "chat.h"

namespace bot::types {

Chat::Chat() : BaseObject()
{
    mFields = {
        TYPE,
        TITLE,
        USERNAME,
        FIRSTNAME,
        LASTNAME,
        PHOTO,
        BIO,
        DESCRIPTION,
        INVITE_LINK,
        PINNED_MESSAGE,
        PERMISSIONS,
        SLOW_MODE_DELAY,
        MESSAGE_AUTO_DELETE_TIME,
        STICKER_SET_NAME,
        CAN_SET_STICKER_SET,
        LINKED_CHAT_ID,
        LOCATION
    };
}

Chat::Chat(ptree& pt)
{
    mFields = {
        TYPE,
        TITLE,
        USERNAME,
        FIRSTNAME,
        LASTNAME,
        PHOTO,
        BIO,
        DESCRIPTION,
        INVITE_LINK,
        PINNED_MESSAGE,
        PERMISSIONS,
        SLOW_MODE_DELAY,
        MESSAGE_AUTO_DELETE_TIME,
        STICKER_SET_NAME,
        CAN_SET_STICKER_SET,
        LINKED_CHAT_ID,
        LOCATION
    };

    for(string& field: mFields)
    {
        string value = pt.get<string>(field);
        add<string>(field, value);
    }
}

string Chat::getType() const
{
    return get(TYPE, string{});
}

void Chat::setType(const string& type)
{
    add<string>(TYPE, type);
}

std::optional<string> Chat::getTitle() const
{
    return get(TITLE, string());
}

void Chat::setTitle(const string title)
{
    add<string>(TYPE, title);
}

std::optional<string> Chat::getUsername() const
{
    return get(USERNAME, string());
}

void Chat::setUsername(const string username)
{
    add<string>(USERNAME, username);
}

std::optional<string> Chat::getFirstName() const
{
    return get(FIRSTNAME, string());
}

void Chat::setFirstName(const string firstName)
{
    add<string>(FIRSTNAME, firstName);
}

std::optional<string> Chat::getLastName() const
{
    return get(LASTNAME, string());
}

void Chat::setLastName(const string value)
{
    add<string>(LASTNAME, value);
}

std::optional<BaseObject> Chat::getPhoto() const
{
    return get(PHOTO, BaseObject{});
}

void Chat::setPhoto(const BaseObject& photo)
{
    add<BaseObject>(PHOTO, photo);
}

std::optional<string> Chat::getBio() const
{
    return get(BIO, string());
}

void Chat::setBio(const string bio)
{
    add<string>(BIO, bio);
}

std::optional<string> Chat::getDescription() const
{
    return get(DESCRIPTION, string());
}

void Chat::setDescription(const string description)
{
    add<string>(DESCRIPTION, description);
}

std::optional<string> Chat::getInviteLink() const
{
    return get(INVITE_LINK, string());
}

void Chat::setInviteLink(const string inviteLink)
{
    add<string>(INVITE_LINK, inviteLink);
}

std::optional<BaseObject> Chat::getPinnedMessage() const
{
    return get(PINNED_MESSAGE, BaseObject{});
}

void Chat::setPinnedMessage(const BaseObject& value)
{
    add<BaseObject>(PINNED_MESSAGE, value);
}

std::optional<BaseObject> Chat::getPermissions() const
{
    return get(PERMISSIONS, BaseObject{});
}

void Chat::setPermissions(const BaseObject& permissions)
{
    add<BaseObject>(PERMISSIONS, permissions);
}

std::optional<int> Chat::getSlowModeDelay() const
{
    return get(SLOW_MODE_DELAY, -1);
}

void Chat::setSlowModeDelay(const int slowModeDelay)
{
    add<int>(SLOW_MODE_DELAY, slowModeDelay);
}

std::optional<int> Chat::getMessageAutoDeleteTime() const
{
    return get(MESSAGE_AUTO_DELETE_TIME, 0);
}

void Chat::setMessageAutoDeleteTime(const int messageAutoDeleteTime)
{
    add<int>(MESSAGE_AUTO_DELETE_TIME, messageAutoDeleteTime);
}

std::optional<string> Chat::getStickerSetName() const
{
    return get(STICKER_SET_NAME, string());
}

void Chat::setStickerSetName(const string stickerSetName)
{
    add<string>(STICKER_SET_NAME, stickerSetName);
}

std::optional<bool> Chat::getCanSetStickerSet() const
{
    return get(CAN_SET_STICKER_SET, false);
}

void Chat::setCanSetStickerSet(const bool canSetStickerSet)
{
    add<bool>(CAN_SET_STICKER_SET, canSetStickerSet);
}

std::optional<int> Chat::getLinkedChatId() const
{
    return get<int>(LINKED_CHAT_ID);
}

void Chat::setLinkedChatId(const int linkedChatId)
{
    add<int>(LINKED_CHAT_ID, linkedChatId);
}

std::optional<BaseObject> Chat::getLocation() const
{
    return get(LOCATION, BaseObject{});
}

void Chat::setLocation(const BaseObject& location)
{
    add<BaseObject>(LOCATION, location);
}

void Chat::fromPtree(const ptree& pt)
{
    for(string& field: mFields)
    {
        string value = pt.get<string>(field);
        add<string>(field, value);
    }
}


}
