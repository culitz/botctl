#pragma once
#include "base_object.h"
#include "fields.h"


namespace bot::types {

class ChatPermissions : public BaseObject
{
public:
    ChatPermissions(
            std::optional<bool> can_send_messages,
            std::optional<bool> can_send_media_messages,
            std::optional<bool> can_send_polls,
            std::optional<bool> can_send_other_messages,
            std::optional<bool> can_add_web_page_previews,
            std::optional<bool> can_change_info,
            std::optional<bool> can_invite_users,
            std::optional<bool> can_pin_messages
    );
    ChatPermissions(string& json);
    ChatPermissions(Value const&);
    virtual ~ChatPermissions() {}

    /// \brief True, if the user is allowed to send text messages, contacts,
    /// locations and venues
    std::optional<bool> can_send_messages;

    /// \brief Boolean	Optional. True, if the user is allowed to send audios,
    /// documents, photos, videos, video notes and voice notes, implies
    /// can_send_messages
    std::optional<bool> can_send_media_messages;


    /// \brief True, if the user is allowed to send polls, implies can_send_messages
    std::optional<bool> can_send_polls;

    /// \brief True, if the user is allowed to send animations,
    /// games, stickers and use inline bots, implies can_send_media_messages
    std::optional<bool> can_send_other_messages;


    /// \brief True, if the user is allowed to add web page
    /// previews to their messages, implies can_send_media_messages
    std::optional<bool> can_add_web_page_previews;

    /// \brief True, if the user is allowed to change the chat
    /// title, photo and other settings. Ignored in public supergroups
    std::optional<bool> can_change_info;

    /// \brief True, if the user is allowed to invite new
    /// users to the chat
    std::optional<bool> can_invite_users;

    /// \brief 	True, if the user is allowed to pin messages.
    /// Ignored in public supergroups
    std::optional<bool> can_pin_messages;

protected:
    virtual void fillDocument(Writer& writer) const override;
    virtual void fillObject(Value const& document) override;
};

}
