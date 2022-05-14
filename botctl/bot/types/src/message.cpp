#include "message.h"

namespace bot::types
{

Message::Message(string& json) : BaseObject()
{
    fromString(json);
}

Message::~Message()
{

}

void Message::fillDocument(Writer &writer)
{
    writer.Key(fields::MESSAGE_ID);
    writer.Int(message_id);

    if(date)
    {
        writer.Key(fields::DATE);
        writer.Int(*date);
    }
    if(forward_from_message_id)
    {
        writer.Key(fields::FORWARD_FROM_MESSAGE_ID);
        writer.Int(*forward_from_message_id);
    }
    if(forward_signature)
    {
        writer.Key(fields::FORWARD_SIGNATURE);
        writer.Int(*forward_date);
    }
    if(forward_sender_name)
    {
        writer.Key(fields::FORWARD_SENDER_NAME);
        writer.Int(*forward_sender_name->c_str());
    }
    if(forward_date)
    {
        writer.Key(fields::FORWARD_DATE);
        writer.Int(*forward_date);
    }
    if(is_automatic_forward)
    {
        writer.Key(fields::IS_AUTOMATIC_FORWARD);
        writer.Bool(*is_automatic_forward);
    }
    if(edit_date)
    {
        writer.Key(fields::EDIT_DATE);
        writer.Int(*edit_date);
    }
    if(has_protected_content)
    {
        writer.Key(fields::HAS_PROTECTED_CONTENT);
        writer.Bool(*has_protected_content);
    }
    if(media_group_id)
    {
        writer.Key(fields::MEDIA_GROUP_ID);
        writer.String(media_group_id->c_str());
    }
    if(author_signature)
    {
        writer.Key(fields::AUTHOR_SIGNATURE);
        writer.String(author_signature->c_str());
    }
    if(text)
    {
        writer.Key(fields::TEXT);
        writer.String(text->c_str());
    }
    if(caption)
    {
        writer.Key(fields::CAPTION);
        writer.String(caption->c_str());
    }
    if(delete_chat_photo)
    {
        writer.Key(fields::DELETE_CHAT_PHOTO);
        writer.Bool(*delete_chat_photo);
    }
    if(group_chat_created)
    {
        writer.Key(fields::GROUP_CHAT_CREATED);
        writer.Bool(*group_chat_created);
    }
    if(supergroup_chat_created)
    {
        writer.Key(fields::SUPERGROUP_CHAT_CREATED);
        writer.Bool(*supergroup_chat_created);
    }
    if(channel_chat_created)
    {
        writer.Key(fields::CHANNEL_CHAT_CREATED);
        writer.Bool(*channel_chat_created);
    }
    if(migrate_to_chat_id)
    {
        writer.Key(fields::MIGRATE_FROM_CHAT_ID);
        writer.Int(*migrate_to_chat_id);
    }
    if(connected_website)
    {
        writer.Key(fields::CONNECTED_WEBSITE);
        writer.String(connected_website->c_str());
    }

}

void Message::fillObject(rapidjson::Value const &document)
{
    message_id = document[fields::MESSAGE_ID].GetInt();
    date = document[fields::DATE].GetInt();
    forward_from_message_id = document[fields::FORWARD_FROM_MESSAGE_ID].GetInt();
    forward_signature = document[fields::FORWARD_SIGNATURE].GetString();
    forward_sender_name = document[fields::FORWARD_SENDER_NAME].GetString();
    forward_date = document[fields::FORWARD_DATE].GetInt();
    is_automatic_forward = document[fields::IS_AUTOMATIC_FORWARD].GetBool();
    edit_date = document[fields::EDIT_DATE].GetInt();
    has_protected_content = document[fields::HAS_PROTECTED_CONTENT].GetBool();
    media_group_id = document[fields::MEDIA_GROUP_ID].GetString();
    author_signature = document[fields::AUTHOR_SIGNATURE].GetString();
    text = document[fields::TEXT].GetString();
    caption = document[fields::CAPTION].GetString();
    delete_chat_photo = document[fields::DELETE_CHAT_PHOTO].GetBool();
    group_chat_created = document[fields::GROUP_CHAT_CREATED].GetBool();
    supergroup_chat_created = document[fields::SUPERGROUP_CHAT_CREATED].GetBool();
    migrate_to_chat_id = document[fields::MIGRATE_FROM_CHAT_ID].GetInt();
    connected_website = document[fields::CONNECTED_WEBSITE].GetString();
    channel_chat_created = document[fields::CHANNEL_CHAT_CREATED].GetBool();
}



}
