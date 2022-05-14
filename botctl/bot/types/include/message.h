#pragma once
#include "base_object.h"
#include <list>
#include <fields.h>

namespace bot::types
{

class Message : public BaseObject
{
public:
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

    Message() {}
    Message(string& json);
    ~Message();

protected:
    virtual void fillDocument(Writer& writer);
    virtual void fillObject(rapidjson::Value const& document);
};

}
