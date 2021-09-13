#include "message.h"

namespace bot::types
{

Message::Message(int id) : BaseObject(id)
{

}

Message::Message(ptree& pt) : BaseObject(pt)
{
    mFields.push_back(MESSAGE_ID);
    mFields.push_back(FROM);
    mFields.push_back(DATE);
    mFields.push_back(CHAT);
    mFields.push_back(FORWARD_FROM);
    mFields.push_back(FORWARD_DATE);
    mFields.push_back(REPLY_TO_MESSAGE);
    mFields.push_back(TEXT);
    mFields.push_back(ENTITIES);
    mFields.push_back(AUDIO);
    mFields.push_back(DOCUMENT);
    mFields.push_back(PHOTO);
    mFields.push_back(STICKER);
    mFields.push_back(VIDEO);
    mFields.push_back(VOICE);
    mFields.push_back(CAPTION);
    mFields.push_back(CONTACT);
    mFields.push_back(LOCATION);
    mFields.push_back(VENUE);
    mFields.push_back(NEW_CHAT_MEMBER);
    mFields.push_back(LEFT_CHAT_MEMBER);
    mFields.push_back(NEW_CHAT_TITLE);
    mFields.push_back(NEW_CHAT_PHOTO);
    mFields.push_back(DELETE_CHAT_PHOTO);
    mFields.push_back(GROUP_CHAT_CREATED);
    mFields.push_back(SUPERGROUP_CHAT_CREATED);
    mFields.push_back(CHANNEL_CHAT_CREATED);
    mFields.push_back(MIGRATE_TO_CHAT_ID);
    mFields.push_back(MIGRATE_FROM_CHAT_ID);
    mFields.push_back(PINNED_MESSAGE);
    init(pt);
}

void Message::setMessageId(string& message_id)
{
    add<string>(MESSAGE_ID, message_id);
}

void Message::setFrom(BaseObject& user)
{
    add<BaseObject>(FROM, user);
}

void Message::setDate(int date)
{
    add<int>(DATE, date);
}

void Message::setChat(BaseObject& chat)
{
    add<BaseObject>(CHAT, chat);
}

void Message::setForwardFrom(BaseObject& user)
{
    add<BaseObject>(FORWARD_FROM, user);
}

void Message::setForwardDate(int date)
{
    add<BaseObject>(FORWARD_DATE, date);
}

void Message::setReplyToMessage(BaseObject& message)
{
    add<BaseObject>(REPLY_TO_MESSAGE, message);
}

void Message::setText(string& text)
{
    add<string>(TEXT, text);
}

void Message::setEntities(std::vector<BaseObject>& entities)
{
    /// @todo Make in BaseObject
}

void Message::setAudio(BaseObject& audio)
{
    add<BaseObject>(AUDIO, audio);
}

void Message::setDocument(BaseObject& documents)
{
    add<BaseObject>(DOCUMENT, documents);
}

void Message::setPhoto(std::vector<BaseObject>& photos)
{
    /// @todo Make in BaseObject
}

void Message::setSticker(BaseObject& sticker)
{
    add<BaseObject>(STICKER, sticker);
}

void Message::setVideo(BaseObject& video)
{
    add<BaseObject>(VIDEO, video);
}

void Message::setVoice(BaseObject& voice)
{
    add<BaseObject>(VOICE, voice);
}

void Message::setCaption(string caption)
{
    add<string>(CAPTION, caption);
}

void Message::setContact(BaseObject& contact)
{
    add<BaseObject>(CAPTION, contact);
}

void Message::setLocation(BaseObject& location)
{
    add<BaseObject>(LOCATION, location);
}

void Message::setVenue(BaseObject& venue)
{
    add<BaseObject>(VENUE, venue);
}

void Message::setNewChatMember(BaseObject& chat_member)
{
    add<BaseObject>(NEW_CHAT_MEMBER, chat_member);
}

void Message::setLeftChatMember(BaseObject& chat_member)
{
    add<BaseObject>(LEFT_CHAT_MEMBER, chat_member);
}

void Message::setNewChatTitle(string title)
{
    add<string>(NEW_CHAT_TITLE, title);
}

void Message::setNewChatPhoto(std::vector<BaseObject>& chat_photo)
{
    /// @todo Make in BaseObject
}

void Message::setDeleteChatPhoto(bool status)
{
    add<bool>(DELETE_CHAT_PHOTO, status);
}

void Message::setGroupChatCreated(bool status)
{
    add<bool>(GROUP_CHAT_CREATED, status);
}

void Message::setSupergroupChatCreated(bool status)
{
    add<bool>(SUPERGROUP_CHAT_CREATED, status);
}

void Message::setChannelChatCreated(bool status)
{
    add<bool>(CHANNEL_CHAT_CREATED, status);
}

void Message::setMigrateToChatId(int id)
{
    add<int>(MIGRATE_TO_CHAT_ID, id);
}

void Message::setMigrateFromChatId(int id)
{
    add<int>(MIGRATE_FROM_CHAT_ID, id);
}

void Message::setPinnedMessage(BaseObject& message)
{
    add<BaseObject>(PINNED_MESSAGE, message);
}

/// Getters
int Message::getMessageId()
{
    return get<int>(MESSAGE_ID, int());
}

std::optional<BaseObject> Message::getFrom()
{
    return get<BaseObject>(FROM);
}

int Message::getDate()
{
   return get<int>(DATE, 0);
}

BaseObject Message::getChat()
{
    return get<BaseObject>(CHAT, BaseObject{});
}

BaseObject Message::getForwardFrom()
{
    return get<BaseObject>(FORWARD_FROM, BaseObject{});
}

std::optional<int> Message::getForwardDate()
{
    return get<int>(FORWARD_DATE);
}

BaseObject Message::getReplyToMessage()
{
    return get<BaseObject>(REPLY_TO_MESSAGE, BaseObject{});
}

std::optional<string> Message::getText()
{
    return get<string>(TEXT);
}

std::vector<BaseObject> Message::getEntities()
{
    return std::vector<BaseObject>();
}

std::optional<BaseObject> Message::getAudio()
{
    return get<BaseObject>(AUDIO);
}

std::optional<BaseObject> Message::getDocument()
{
    return get<BaseObject>(DOCUMENT);
}

std::vector<BaseObject> Message::getPhoto()
{
    return std::vector<BaseObject>();
}

std::optional<BaseObject> Message::getSticker()
{
    return get<BaseObject>(STICKER);
}

std::optional<BaseObject> Message::getVideo()
{
    return get<BaseObject>(VIDEO);
}

std::optional<BaseObject> Message::getVoice()
{
    return get<BaseObject>(VOICE);
}

std::optional<string> Message::getCaption()
{
    return get<string>(CAPTION);
}

std::optional<BaseObject> Message::getContact()
{
    return get<BaseObject>(CONTACT);
}

std::optional<BaseObject> Message::getLocation()
{
    return get<BaseObject>(LOCATION);
}

std::optional<BaseObject> Message::getVenue()
{
    return get<BaseObject>(VENUE);
}

std::optional<BaseObject> Message::getNewChatMember()
{
    return get<BaseObject>(NEW_CHAT_MEMBER);
}

std::optional<BaseObject> Message::getLeftChatMember()
{
    return get<BaseObject>(LEFT_CHAT_MEMBER);
}

std::optional<string> Message::getNewChatTitle()
{
    return get<string>(NEW_CHAT_TITLE);
}

std::vector<BaseObject> Message::getNewChatPhoto()
{
    return std::vector<BaseObject>();
}

std::optional<bool> Message::getDeleteChatPhoto()
{
    return get<bool>(DELETE_CHAT_PHOTO);
}

std::optional<bool> Message::getGroupChatCreated()
{
    return get<bool>(GROUP_CHAT_CREATED);
}

std::optional<bool> Message::getSupergroupChatCreated()
{
    return get<bool>(SUPERGROUP_CHAT_CREATED);
}

std::optional<bool> Message::getChannelChatCreated()
{
    return get<bool>(CHANNEL_CHAT_CREATED);
}

std::optional<int> Message::getMigrateToChatId()
{
    return get<int>(MIGRATE_TO_CHAT_ID);
}

std::optional<int> Message::getMigrateFromChatId()
{
    return get<int>(MIGRATE_FROM_CHAT_ID);
}

std::optional<BaseObject> Message::getPinnedMessage()
{
    return get<BaseObject>(PINNED_MESSAGE);
}


}
