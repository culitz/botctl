#pragma once

#include "base_object.h"

namespace bot::types {

class User : public BaseObject
{
public:
    inline static string IS_BOT                         {"is_bot"};
    inline static string FIRST_NAME                     {"first_name"};
    inline static string LAST_NAME                      {"last_name"};
    inline static string USERNAME                       {"username"};
    inline static string LANGUAGE_CODE                  {"language_code"};
    inline static string CAN_JOIN_GROUPS                {"can_join_groups"};
    inline static string CAN_READ_ALL_GROUP_MESSAGES    {"can_read_all_group_messages"};
    inline static string SUPPORT_INLINE_QUERIES         {"supports_inline_queries"};

    bool                                                is_bot;
    string                                              first_name;
    std::optional<string>                               last_name;
    std::optional<string>                               username;
    std::optional<string>                               language_code;
    std::optional<bool>                                 can_join_groups;
    std::optional<bool>                                 can_read_all_group_messages;
    std::optional<bool>                                 supports_inline_queries;

    User();
    User(Value const& value);
    User(string& json);
    User(const User&);
    User(
        string first_name,
        bool is_bot,
        std::optional<string> last_name = {},
        std::optional<string> username = {},
        std::optional<string> language_code = {},
        std::optional<bool> can_join_groups = {},
        std::optional<bool> can_read_all_group_messages = {},
        std::optional<bool> supports_inline_queries = {}
    );
    virtual ~User();

    virtual void fromNestedObject(const Value &value) override;
private:
    typedef BaseObject Parent;
    virtual void fillObject(rapidjson::Value const& document) override;
    virtual void fillDocument(Writer& writer) const override;
};


}
