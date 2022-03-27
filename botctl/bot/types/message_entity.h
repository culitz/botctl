#pragma once
#include "user.h"
#include "base_object.h"

namespace bot::types
{

class MessageEntity : public BaseObject
{
public:
    inline static const string TYPE = "type";
    inline static const string OFFSET = "offset";
    inline static const string LENGTH = "length";
    inline static const string URL = "url";
    inline static const string USER = "user";
    inline static const string LANGUAGE = "language";

    string type;
    int offset;
    int length;
    std::optional<string> url;
    std::optional<User> user;
    std::optional<string> language;

    MessageEntity(const Value& value);
    MessageEntity(string& json);
    MessageEntity() {}
    ~MessageEntity();

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(rapidjson::Value const& document);
};

}
