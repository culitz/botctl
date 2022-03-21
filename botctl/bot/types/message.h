#pragma once
#include "base_object.h"
#include <list>

namespace bot::types
{

class Message : public BaseObject
{
public:
    inline static const string MESSAGE_ID               {"message_id"};
    inline static const string FROM                     {"from"};
    inline static const string SENDER_CHAT              {"sender_chat"};
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

    inline static const string FORWARD_FROM_MESSAGE_ID = "forward_from_message_id";
    inline static const string FORWARD_SIGNATURE = "forward_signature";
    inline static const string FORWARD_SENDER_NAME = "forward_sender_name";
    inline static const string IS_AUTOMATIC_FORWARD = "is_automatic_forward";
    inline static const string EDIT_DATE = "edit_date";
    inline static const string HAS_PROTECTED_CONTENT = "has_protected_content";
    inline static const string MEDIA_GROUP_ID = "media_group_id";
    inline static const string AUTHOR_SIGNATURE = "author_signature";
    inline static const string CONNECTED_WEBSITE = "connected_website";


    int                                                 message_id;
    std::optional<BaseObject>                           from;
    std::optional<BaseObject>                           sender_chat;
    std::optional<int>                                  date;
    std::optional<BaseObject>                           chat;
    std::optional<BaseObject>                           forward_from;
    std::optional<BaseObject>                           forward_from_chat;
    std::optional<int>                                  forward_from_message_id;
    std::optional<string>                               forward_signature;
    std::optional<string>                               forward_sender_name;
    std::optional<int>                                  forward_date;
    std::optional<bool>                                 is_automatic_forward;
    std::optional<BaseObject>                           reply_to_message;
    std::optional<BaseObject>                           via_bot;
    std::optional<int>                                  edit_date;
    std::optional<bool>                                 has_protected_content;
    std::optional<string>                               media_group_id;
    std::optional<string>                               author_signature;
    std::optional<string>                               text;
    std::optional<std::list<BaseObject>>                entities;
    std::optional<BaseObject>                           animation;
    std::optional<BaseObject>                           audio;
    std::optional<BaseObject>                           document;
    std::optional<std::list<BaseObject>>                photo;
    std::optional<BaseObject>                           sticker;
    std::optional<BaseObject>                           video;
    std::optional<BaseObject>                           video_note;
    std::optional<BaseObject>                           voice;
    std::optional<string>                               caption;
    std::optional<std::list<BaseObject>>                caption_entities;
    std::optional<BaseObject>                           contact;
    std::optional<BaseObject>                           dice;
    std::optional<BaseObject>                           game;
    std::optional<BaseObject>                           pool;
    std::optional<BaseObject>                           venue;
    std::optional<BaseObject>                           location;
    std::optional<std::list<BaseObject>>                new_chat_members;
    std::optional<BaseObject>                           left_chat_member;
    std::optional<string>                               new_chat_title;
    std::optional<std::list<BaseObject>>                new_chat_photo;
    std::optional<bool>                                 delete_chat_photo;
    std::optional<bool>                                 group_chat_created;
    std::optional<bool>                                 supergroup_chat_created;
    std::optional<bool>                                 channel_chat_created;
    std::optional<BaseObject>                           message_auto_delete_timer_changed;
    std::optional<int>                                  migrate_to_chat_id;
    std::optional<BaseObject>                           pinned_message;
    std::optional<BaseObject>                           invoice;
    std::optional<BaseObject>                           successful_payment;
    std::optional<string>                               connected_website;
    std::optional<BaseObject>                           passport_data;
    std::optional<BaseObject>                           proximity_alert_triggered;
    std::optional<BaseObject>                           voice_chat_scheduled;
    std::optional<BaseObject>                           voice_chat_started;
    std::optional<BaseObject>                           voice_chat_ended;
    std::optional<BaseObject>                           voice_chat_participants_invited;
    std::optional<BaseObject>                           reply_markup;

    Message(string& json);
    ~Message();

protected:
    virtual void fillDocument(Writer& writer);
    virtual void fillObject(rapidjson::Value const& document);
};

}
