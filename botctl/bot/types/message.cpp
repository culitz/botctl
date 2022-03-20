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
    writer.Key(MESSAGE_ID.c_str());
    writer.Int(message_id);

    if(date)
    {
        writer.Key(DATE.c_str());
        writer.Int(*date);
    }
    if(forward_from_message_id)
    {
        writer.Key(FORWARD_FROM_MESSAGE_ID.c_str());
        writer.Int(*forward_from_message_id);
    }
    if(forward_signature)
    {
        writer.Key(FORWARD_SIGNATURE.c_str());
        writer.Int(*forward_date);
    }
    if(forward_sender_name)
    {
        writer.Key(FORWARD_SENDER_NAME.c_str());
        writer.Int(*forward_sender_name->c_str());
    }
    if(forward_date)
    {
        writer.Key(FORWARD_DATE.c_str());
        writer.Int(*forward_date);
    }
    if(is_automatic_forward)
    {
        writer.Key(IS_AUTOMATIC_FORWARD.c_str());
        writer.Bool(*is_automatic_forward);
    }
    if(edit_date)
    {
        writer.Key(EDIT_DATE.c_str());
        writer.Int(*edit_date);
    }
    if(has_protected_content)
    {
        writer.Key(HAS_PROTECTED_CONTENT.c_str());
        writer.Bool(*has_protected_content);
    }
    if(media_group_id)
    {
        writer.Key(MEDIA_GROUP_ID.c_str());
        writer.String(media_group_id->c_str());
    }
    if(author_signature)
    {
        writer.Key(AUTHOR_SIGNATURE.c_str());
        writer.String(author_signature->c_str());
    }
    if(text)
    {
        writer.Key(TEXT.c_str());
        writer.String(text->c_str());
    }
    if(caption)
    {
        writer.Key(CAPTION.c_str());
        writer.String(caption->c_str());
    }
    if(delete_chat_photo)
    {
        writer.Key(DELETE_CHAT_PHOTO.c_str());
        writer.Bool(*delete_chat_photo);
    }
    if(group_chat_created)
    {
        writer.Key(GROUP_CHAT_CREATED.c_str());
        writer.Bool(*group_chat_created);
    }
    if(supergroup_chat_created)
    {
        writer.Key(SUPERGROUP_CHAT_CREATED.c_str());
        writer.Bool(*supergroup_chat_created);
    }
    if(channel_chat_created)
    {
        writer.Key(CHANNEL_CHAT_CREATED.c_str());
        writer.Bool(*channel_chat_created);
    }
    if(migrate_to_chat_id)
    {
        writer.Key(MIGRATE_FROM_CHAT_ID.c_str());
        writer.Int(*migrate_to_chat_id);
    }
    if(connected_website)
    {
        writer.Key(CONNECTED_WEBSITE.c_str());
        writer.String(connected_website->c_str());
    }

}

void Message::fillObject(rapidjson::Document &document)
{
    message_id = document[MESSAGE_ID.c_str()].GetInt();
    date = document[DATE.c_str()].GetInt();
    forward_from_message_id = document[FORWARD_FROM_MESSAGE_ID.c_str()].GetInt();
    forward_signature = document[FORWARD_SIGNATURE.c_str()].GetString();
    forward_sender_name = document[FORWARD_SENDER_NAME.c_str()].GetString();
    forward_date = document[FORWARD_DATE.c_str()].GetInt();
    is_automatic_forward = document[IS_AUTOMATIC_FORWARD.c_str()].GetBool();
    edit_date = document[EDIT_DATE.c_str()].GetInt();
    has_protected_content = document[HAS_PROTECTED_CONTENT.c_str()].GetBool();
    media_group_id = document[MEDIA_GROUP_ID.c_str()].GetString();
    author_signature = document[AUTHOR_SIGNATURE.c_str()].GetString();
    text = document[TEXT.c_str()].GetString();
    caption = document[CAPTION.c_str()].GetString();
    delete_chat_photo = document[DELETE_CHAT_PHOTO.c_str()].GetBool();
    group_chat_created = document[GROUP_CHAT_CREATED.c_str()].GetBool();
    supergroup_chat_created = document[SUPERGROUP_CHAT_CREATED.c_str()].GetBool();
    migrate_to_chat_id = document[MIGRATE_FROM_CHAT_ID.c_str()].GetInt();
    connected_website = document[CONNECTED_WEBSITE.c_str()].GetString();
    channel_chat_created = document[CHANNEL_CHAT_CREATED.c_str()].GetBool();
}



}
