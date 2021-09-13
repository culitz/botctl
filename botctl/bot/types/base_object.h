#pragma once

#include <memory>
#include <optional>
#include <map>
#include <type_traits>
#include <algorithm>
#include <any>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

namespace bot::types {

typedef std::string string;
typedef boost::property_tree::ptree ptree;
typedef std::map<string, std::pair<string, int>> DataMap;

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

class BaseObject : DataMap
{
protected:
    /// Filling always in construsctor
    std::vector<string> mFields;

    /// Filling DataMap from mFields
    void init(ptree& pt);

private:
    typedef std::map<string, string> Parent;

    operator int() const { return -1; }
    operator std::string() { return toString(); }

    /// Redefenition of operator << need for serialize BaseObject to json
    friend std::ostream& operator<<(std::ostream& os, const BaseObject& b);
    friend bool operator==(const BaseObject& left, const BaseObject& right);
    friend bool operator!=(const BaseObject& left, const BaseObject& right);

    /**
    * @brief get
    * Getting data by key from type-object
    * @param key - keyword
    * @param default_value - method return value if keyword not exist
    * @return T
    */
    bool get(string key, string& value, string default_value) const;
    bool get(string key, bool default_value) const;
    int get(string key, int default_value) const;
    double get(string key, double default_value) const;
    string get(string key, string default_value) const;
    BaseObject get(string key, BaseObject default_value ) const;
    std::vector<BaseObject> get(string key, std::vector<BaseObject> default_value) const;

public:
    inline static const std::string ID_NAME {"id"};
    BaseObject() : DataMap() { mFields = {ID_NAME}; }
    BaseObject(int id);
    BaseObject( ptree& );
    ~BaseObject() {}

    /**
     * @brief add
     * Add field to type-object
     */
    template <typename T>
    void add(string key, T item)
    {
        std::stringstream ss;

        /// fill metadata to value
        int type;
        if(std::is_same<string, T>::value)
        {
            type = Types::STRING;
            ss << item;
        }
        else if( std::is_same<int, T>::value)
        {
            type = Types::INTEGER;
            ss << item;
        }
        else if( std::is_same<float, T>::value)
        {
            type = Types::FLOAT;
            ss << item;
        }
        else if( std::is_same<bool, T>::value)
        {
            type = Types::BOOL;
            ss << item;
            string serialized_value = ss.str();
            string json_value = (serialized_value == "1") ? "true": "false";
            ss.str(string{});
            ss << json_value;
        }
        else
        {
            type = Types::OBJECT;
            ss << item;
        }

        /// {value, metadata}
        std::pair<string, int> data = {ss.str(), type};
        insert(std::make_pair(key, data));
    }

    template<typename T>
    std::optional<T> get(string const key) const
    {
        T tmp;
        std::optional<T> opt = get(key, tmp);
        return opt;
    }

    template<typename T>
    T get(string const key, T default_value) const
    {
        return get(key, default_value);
    }

    template<typename T>
    void fillItem(ptree& pt, string key, std::optional<T> opt_value) const
    {
        if(opt_value.has_value())
            pt.add<T>(key, opt_value.value());
    }

    void fillObject(ptree& pt, string key, std::optional<BaseObject> opt_value) const
    {
        if(opt_value.has_value())
            pt.add_child(key, *opt_value.value().getPtree());
    }
    /**
     * @brief getId - getter for id field
     * @return
     */
    int getId() const;

    /**
     * @brief setId - setter for id field
     * @param value of field "id"
     */
    void setId(int value);

    /**
     * @brief getPtree - Get data of type-object as std::shared_ptr<boost::ptree>
     * @return std::shared_ptr<boost::ptree>
     */
    virtual std::shared_ptr<ptree> getPtree() const;

    /**
     * @brief fromPtree - fill type-object from ptree
     */
    virtual void fromPtree(const ptree&);

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
