#pragma once
#include "base_object.h"
#include "user.h"
#include "fields.h"

namespace bot::types {

class ChatInviteLink : public BaseObject {
public:
    ChatInviteLink();
    ChatInviteLink(std::string&);
    ChatInviteLink(Value const& value);
    ChatInviteLink(
        std::string invite_link,
        User creator,
        bool creates_join_request,
        bool is_primary,
        bool is_revoked,
        std::optional<std::string> name = {},
        std::optional<int> expire_date = {},
        std::optional<int> member_limit = {},
        std::optional<int> pending_join_request_count = {}
    );

    virtual ~ChatInviteLink() {}

    /**
     * @brief The invite link. If the link was created by another chat 
     * administrator, then the second part of the link will be replaced 
     *   with “…”.
     */
    std::string invite_link;	
    
    /**
     * @brief Creator of the link
     */
    User creator;

    /**
     * @brief 	Boolean	True, if users joining the chat via the link need 
     * to be approved by chat administrators
     */
    bool creates_join_request;

    /**
     * @brief True, if the link is primary
     */
    bool is_primary;
    /**
     * @brief True, if the link is revoked
     */
    bool is_revoked;
    /**
     * @brief Invite link name
     */
    std::optional<std::string> name;
    /**
     * @brief Point in time (Unix timestamp) 
     * when the link will expire or has been expired
     */
    std::optional<int> expire_date;	
    /**
     * @brief Maximum number of users that can be members of the chat 
     * simultaneously after joining the chat via this invite link; 1-99999
     */
    std::optional<int> member_limit;
    /**
     * @brief Number of pending join requests created using this link
     */
    std::optional<int> pending_join_request_count;

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);	
};

}