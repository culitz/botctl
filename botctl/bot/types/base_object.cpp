#include "base_object.h"


namespace bot::types {


BaseObject::BaseObject(const BaseObject &object)
{
    id = object.id;
}

BaseObject::BaseObject(int id) : id (id) {}

BaseObject::BaseObject(Value &value)
{
    fromNestedObject(value);
}

void BaseObject::fillDocument(Writer& writer) const
{
    writer.Key(ID_NAME.c_str());
    writer.Int(id);
}

void BaseObject::fillObject(rapidjson::Document &document)
{
    id = document[ID_NAME.c_str()].GetInt();
}

std::string BaseObject::toString() const
{
    auto buffer = std::shared_ptr<StringBuffer>(new StringBuffer);
    Writer writer(*buffer);
    writer.StartObject();
    fillDocument(writer);
    writer.EndObject();
    return buffer->GetString();
}

size_t BaseObject::hash() const
{
    size_t hash = std::hash<int>{}(0);
    return hash;
}

std::optional<string> BaseObject::getOptString(rapidjson::Document &document, string key)
{
    if(document.HasMember(key.c_str()))
    {
        string value = document[key.c_str()].GetString();
        return std::optional<string>(value);
    }
    return std::optional<string>();
}

std::optional<bool> BaseObject::getOptBool(rapidjson::Document &document, string key)
{
    if(document.HasMember(key.c_str()))
    {
        bool value = document[key.c_str()].GetBool();
        return std::optional<bool>(value);
    }
    return std::optional<bool>();
}

std::optional<int> BaseObject::getOptInt(rapidjson::Document &document, string key)
{
    if(document.HasMember(key.c_str()))
    {
        int value = document[key.c_str()].GetInt();
        return std::optional<int>(value);
    }
    return std::optional<int>();
}

std::optional<string> BaseObject::getOptString(Value &value, string key)
{
    if(value.HasMember(key.c_str()))
    {
        string value = document[key.c_str()].GetString();
        return std::optional<string>(value);
    }
    return std::optional<string>();
}

std::optional<bool> BaseObject::getOptBool(Value &value, string key)
{
    if(value.HasMember(key.c_str()))
    {
        bool value = document[key.c_str()].GetBool();
        return std::optional<bool>(value);
    }
    return std::optional<bool>();
}

std::optional<int> BaseObject::getOptInt(Value &value, string key)
{
    if(value.HasMember(key.c_str()))
    {
        int value = document[key.c_str()].GetInt();
        return std::optional<int>(value);
    }
    return std::optional<int>();
}

void BaseObject::asNestedObject(Writer &writer) const
{
    writer.StartObject();
    fillDocument(writer);
    writer.EndObject();
}

void BaseObject::fromNestedObject(Value &value)
{
    id = value[ID_NAME.c_str()].GetInt();
}

void BaseObject::fromString(const string& object)
{
    auto document = std::shared_ptr<rapidjson::Document>(new rapidjson::Document);
    document->Parse(object.c_str());
    bool erros = document->HasParseError();
    fillObject(*document);
}

}
