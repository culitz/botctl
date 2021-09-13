#pragma once
#include "base_object.h"

namespace bot::types
{

class Message : public BaseObject
{
public:
    inline static const string MESSAGE_ID               {"message_id"};
    inline static const string FROM                     {"from"};
    inline static const string DATE                     {"date"};
    inline static const string CHAT                     {"chat"};
    inline static const string FORWARD_FROM             {"forward_from"};
    inline static const string FORWARD_DATE             {"forward_date"};
    inline static const string REPLY_TO_MESSAGE         {"reply_to_message"};
    inline static const string TEXT                     {"text"};
    inline static const string ENTITIES                 {"entities"};
    inline static const string AUDIO                    {"audio"};
    inline static const string DOCUMENT                 {"document"};
    inline static const string PHOTO                    {"photo"};
    inline static const string STICKER                  {"sticker"};
    inline static const string VIDEO                    {"video"};
    inline static const string VOICE                    {"voice"};
    inline static const string CAPTION                  {"caption"};
    inline static const string CONTACT                  {"contact"};
    inline static const string LOCATION                 {"location"};
    inline static const string VENUE                    {"venue"};
    inline static const string NEW_CHAT_MEMBER          {"new_chat_member"};
    inline static const string LEFT_CHAT_MEMBER         {"left_chat_member"};
    inline static const string NEW_CHAT_TITLE           {"new_chat_title"};
    inline static const string NEW_CHAT_PHOTO           {"new_chat_photo"};
    inline static const string DELETE_CHAT_PHOTO        {"delete_chat_photo"};
    inline static const string GROUP_CHAT_CREATED       {"group_chat_created"};
    inline static const string SUPERGROUP_CHAT_CREATED  {"supergroup_chat_created"};
    inline static const string CHANNEL_CHAT_CREATED     {"channel_chat_created"};
    inline static const string MIGRATE_TO_CHAT_ID       {"migrate_to_chat_id"};
    inline static const string MIGRATE_FROM_CHAT_ID     {"migrate_from_chat_id"};
    inline static const string PINNED_MESSAGE           {"pinned_message"};

    Message( int id );
    Message( ptree& );

    /// getters
    void setMessageId(string& message_id);
    void setFrom(BaseObject& user);
    void setDate(int date);
    void setChat(BaseObject& chat);
    void setForwardFrom(BaseObject& user);
    void setForwardDate(int date);
    void setReplyToMessage(BaseObject& message);
    void setText(string& message);
    void setEntities(std::vector<BaseObject>& entities);
    void setAudio(BaseObject& audio);
    void setDocument(BaseObject& documents);
    void setPhoto(std::vector<BaseObject>& photos);
    void setSticker(BaseObject& sticker);
    void setVideo(BaseObject& video);
    void setVoice(BaseObject& voice);
    void setCaption(string caption);
    void setContact(BaseObject& contact);
    void setLocation(BaseObject& location);
    void setVenue(BaseObject& venue);
    void setNewChatMember(BaseObject& chat_member);
    void setLeftChatMember(BaseObject &chat_member);
    void setNewChatTitle(string title);
    void setNewChatPhoto(std::vector<BaseObject>& chat_photo);
    void setDeleteChatPhoto(bool status);
    void setGroupChatCreated(bool status);
    void setSupergroupChatCreated(bool status);
    void setChannelChatCreated(bool status);
    void setMigrateToChatId(int id);
    void setMigrateFromChatId(int id);
    void setPinnedMessage(BaseObject& message);

    /// Setters
    int                         getMessageId();
    std::optional<BaseObject>   getFrom();
    int                         getDate();
    BaseObject                  getChat();
    BaseObject                  getForwardFrom();
    std::optional<int>          getForwardDate();
    BaseObject                  getReplyToMessage();
    std::optional<string>       getText();
    std::vector<BaseObject>     getEntities();
    std::optional<BaseObject>   getAudio();
    std::optional<BaseObject>   getDocument();
    std::vector<BaseObject>     getPhoto();
    std::optional<BaseObject>   getSticker();
    std::optional<BaseObject>   getVideo();
    std::optional<BaseObject>   getVoice();
    std::optional<string>       getCaption();
    std::optional<BaseObject>   getContact();
    std::optional<BaseObject>   getLocation();
    std::optional<BaseObject>   getVenue();
    std::optional<BaseObject>   getNewChatMember();
    std::optional<BaseObject>   getLeftChatMember();
    std::optional<string>       getNewChatTitle();
    std::vector<BaseObject>     getNewChatPhoto();
    std::optional<bool>         getDeleteChatPhoto();
    std::optional<bool>         getGroupChatCreated();
    std::optional<bool>         getSupergroupChatCreated();
    std::optional<bool>         getChannelChatCreated();
    std::optional<int>          getMigrateToChatId();
    std::optional<int>          getMigrateFromChatId();
    std::optional<BaseObject>   getPinnedMessage();
};

}
