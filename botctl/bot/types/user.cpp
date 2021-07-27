#include "user.h"


namespace bot::types {

User::User(ptree& pt) : BaseObject(pt)
{
    mFields = {
        IS_BOT,
        FIRST_NAME,
        LAST_NAME,
        USERNAME,
        LANGUAGE_CODE,
        CAN_JOIN_GROUPS,
        CAN_READ_ALL_GROUP_MESSAGES,
        SUPPORT_INLINE_QUERIES
    };

    for(string& field: mFields)
    {
        string value = pt.get<string>(field);
        add<string>(field, value);
    }
}

User::User()
{
    mFields = {
        IS_BOT,
        FIRST_NAME,
        LAST_NAME,
        USERNAME,
        LANGUAGE_CODE,
        CAN_JOIN_GROUPS,
        CAN_READ_ALL_GROUP_MESSAGES,
        SUPPORT_INLINE_QUERIES
    };
}

User::~User()
{

}

bool User::isBot()
{
    return get(User::IS_BOT, false);
}

string User::getFirstName()
{
    return get(User::FIRST_NAME, string());
}

std::optional<string> User::getLastName()
{
    return get<string>(User::LAST_NAME);
}

std::optional<string> User::getUserName()
{
    return get<string>(User::USERNAME);
}

std::optional<string> User::getLanguageCode()
{
    return get<string>(User::LANGUAGE_CODE);
}

bool User::canJoinGroups()
{
    return get(User::CAN_JOIN_GROUPS, false);
}

bool User::canReadAllGroupMessages()
{
    return get(User::CAN_READ_ALL_GROUP_MESSAGES, false);
}

bool User::supportInlineQueries()
{
    return get(User::SUPPORT_INLINE_QUERIES, false);
}

}
