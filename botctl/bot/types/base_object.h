#pragma once

#include <memory>
#include <optional>
#include <map>
#include <type_traits>
#include <algorithm>
#include <any>
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"



namespace bot::types {

typedef std::string string;
typedef rapidjson::StringBuffer StringBuffer;
typedef rapidjson::Writer<StringBuffer> Writer;
typedef rapidjson::Value Value;

enum Types
{
    BOOL,
    INTEGER,
    FLOAT,
    STRING,
    OBJECT
};

/**
 * @brief The BaseObject class
 * Implement base functions and attributes
 * for telegram-bot api types
 *
 * data mapping inside BaseObject
 *  std::map:
 *      string key
 *      pair:
 *          string value
 *          int type
 */

class BaseObject
{
public:
    inline static const std::string ID_NAME {"id"};
    BaseObject(){}
    BaseObject(const BaseObject&);
    BaseObject(int id);
    BaseObject(Value& value);
    ~BaseObject() {}

     int id;

    /**
     * @brief fromString - fille type-object from json string
     * @param object json string
     */
    virtual void fromString( const string& object );

    /**
     * @brief toString - get json string represent of object
     * @return
     */
    virtual std::string toString() const;
    virtual size_t hash() const;
    std::optional<string> getOptString(rapidjson::Document& document, string key);
    std::optional<bool> getOptBool(rapidjson::Document& document, string key);
    std::optional<int> getOptInt(rapidjson::Document& document, string key);

    std::optional<string> getOptString(Value& value, string key);
    std::optional<bool> getOptBool(Value& value, string key);
    std::optional<int> getOptInt(Value& value, string key);

    void asNestedObject(Writer& writer) const;
    virtual void fromNestedObject(Value& value);
protected:
    rapidjson::Document document;
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(rapidjson::Document& document);

private:
    operator int() const { return -1; }
    operator std::string() { return toString(); }

    /// Redefenition of operator << need for serialize BaseObject to json
    friend std::ostream& operator<<(std::ostream& os, const BaseObject& b);
    friend bool operator==(const BaseObject& left, const BaseObject& right);
    friend bool operator!=(const BaseObject& left, const BaseObject& right);
};

inline std::ostream& operator<<(std::ostream& os, const BaseObject& b)
{
    os << b.toString();
    return os;
}

inline bool operator==(const BaseObject& left, const BaseObject& right)
{
    return left.hash() == right.hash();
}

inline bool operator!=(const BaseObject& left, const BaseObject& right)
{
    return left.hash() != right.hash();
}

}
