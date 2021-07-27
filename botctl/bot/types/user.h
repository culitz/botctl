#pragma once

#include "base_object.h"

namespace bot::types {

class User : public BaseObject
{
public:
    inline static string IS_BOT { "is_bot" };
    inline static string FIRST_NAME { "first_name" };
    inline static string LAST_NAME { "last_name" };
    inline static string USERNAME { "username" };
    inline static string LANGUAGE_CODE { "language_code" };
    inline static string CAN_JOIN_GROUPS { "can_join_groups" };
    inline static string CAN_READ_ALL_GROUP_MESSAGES { "can_read_all_group_messages" };
    inline static string SUPPORT_INLINE_QUERIES { "supports_inline_queries" };

    User(ptree&);
    User();
    ~User();

    bool isBot();
    string getFirstName();
    std::optional<string> getLastName();
    std::optional<string> getUserName();
    std::optional<string> getLanguageCode();

    bool canJoinGroups();
    bool canReadAllGroupMessages();
    bool supportInlineQueries();
};


}
