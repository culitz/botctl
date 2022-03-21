#include "base_object.h"
#include <iostream>

namespace bot::types {


BaseObject::BaseObject(const BaseObject &object) {
    id = object.id;
}

BaseObject::BaseObject(int id) : id (id) {}

BaseObject::BaseObject(Value const& value) {
    fromNestedObject(value);
}

void BaseObject::fillDocument(Writer& writer) const {
    writer.Key(ID_NAME.c_str());
    writer.Int(id);
}

void BaseObject::fillObject(Value const &document) {
    id = document[ID_NAME.c_str()].GetInt();
}

std::string BaseObject::toString() const {
    auto buffer = std::shared_ptr<StringBuffer>(new StringBuffer);
    Writer writer(*buffer);
    writer.StartObject();
    fillDocument(writer);
    writer.EndObject();
    return buffer->GetString();
}

size_t BaseObject::hash() const {
    size_t hash = std::hash<int>{}(0);
    return hash;
}


std::optional<string> BaseObject::getOptString(Value const& value, string key) {
    std::cout << key << std::endl;
    if(value.HasMember(key.c_str())) {
        string s = value[key.c_str()].GetString();
        return std::optional<string>(s);
    }
    return std::optional<string>();
}

std::optional<bool> BaseObject::getOptBool(Value const& value, string key) {
    if(value.HasMember(key.c_str())) {
        bool b = value[key.c_str()].GetBool();
        return std::optional<bool>(b);
    }
    return std::optional<bool>();
}

std::optional<int> BaseObject::getOptInt(Value const& value, string key) {
    if(value.HasMember(key.c_str())) {
        int i = value[key.c_str()].GetInt();
        return std::optional<int>(i);
    }
    return std::optional<int>();
}

void BaseObject::asNestedObject(Writer &writer) const {
    writer.StartObject();
    fillDocument(writer);
    writer.EndObject();
}

void BaseObject::fromNestedObject(Value const &value) {
    id = value[ID_NAME.c_str()].GetInt();
}

void BaseObject::fromString(const string& object) {
    auto document = std::shared_ptr<rapidjson::Document>(new rapidjson::Document);
    document->Parse(object.c_str());
    bool erros = document->HasParseError();
    fillObject(*document);
}

}
