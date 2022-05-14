#pragma once
#include "base_object.h"
#include "fields.h"

namespace bot::types {

/**
 * @brief Represents the rights of an administrator in a chat.
 * 
 */
class ChatAdministratorRights : public BaseObject {
public:
    ChatAdministratorRights();
    ChatAdministratorRights(std::string&);
    ChatAdministratorRights(Value const&);
    ChatAdministratorRights(
        bool is_anonymous,
        bool can_manage_chat,
        bool can_delete_messages,
        bool can_manage_video_chats,
        bool can_restrict_members,
        bool can_promote_members,
        bool can_change_info,
        bool can_invite_users,
        std::optional<bool> can_post_messages = {},
        std::optional<bool> can_edit_messages = {},
        std::optional<bool> can_pin_messages = {}
    );

    /** 
     * \brief True, if the user's presence in the chat is hidden
     */
    bool is_anonymous;

    /**
     * @brief True, if the administrator can access the chat event log, 
     * chat statistics, message statistics in channels, see channel members, 
     * see anonymous administrators in supergroups and ignore slow mode. 
     * Implied by any other administrator privilege
     */
    bool can_manage_chat;

    /**
     * @brief True, if the administrator can delete messages of other users
     */
    bool can_delete_messages;

    /**
     * @brief True, if the administrator can manage video chats
     */
    bool can_manage_video_chats;

    /**
     * @brief True, if the administrator can restrict, ban or unban chat 
     * members can_promote_members	Boolean	
     */
    bool can_restrict_members;

    /**
     * @brief True, if the administrator can add new administrators with
     * a subset of their own privileges or demote administrators that he 
     * has promoted, directly or indirectly (promoted by administrators that 
     * were appointed by the user)
     */
    bool can_promote_members;

    /**
     * @brief True, if the user is allowed to change the chat title, 
     * photo and other settings
     */
    bool can_change_info;

    /**
     * @brief True, if the user is allowed to invite new users to the chat
     */
    bool can_invite_users;

    /**
     * @brief True, if the administrator can post in the channel; channels only
     */
    std::optional<bool> can_post_messages;

    /**
     * @brief True, if the administrator can edit messages of other users 
     * and can pin messages; channels only
     */
    std::optional<bool> can_edit_messages;

    /**
     * @brief rue, if the user is allowed to pin messages; groups 
     * and supergroups only
     */
    std::optional<bool> can_pin_messages;

protected:
    virtual void fillDocument(Writer& writer) const override;
    virtual void fillObject(Value const& document) override;
};

}