#include "base_object.h"

namespace bot::types {


BaseObject::BaseObject(int id) : DataMap()
{
    mFields = {ID_NAME};
    add<int>(ID_NAME, id);
}

BaseObject::BaseObject(ptree& pt) : DataMap()
{
    mFields = {ID_NAME};
    string id = pt.get<string>(ID_NAME);
    add<string>(ID_NAME, id);
}

int BaseObject::get(string key, int default_value) const
{
    string value;
    if(get(key, value, string()))
        return stoi(value);
    return default_value;
}

double BaseObject::get(string key, double default_value) const
{
    string value;
    if(get(key, value, string()))
        return stod(value);
    return default_value;
}

string BaseObject::get(string key, string default_value) const
{
    string value;
    get(key, value, default_value);
    return value;
}

BaseObject BaseObject::get(string key, BaseObject default_value) const
{
    string value;
    if(get(key, value, string()))
    {
        BaseObject b;
        b.fromString(value);
        return b;
    }
    return default_value;
}

bool BaseObject::get(string key, string& value, string default_value) const
{
    auto iter = find(key);
    if(iter == end())
    {
        value = default_value;
        return false;
    }

    std::pair<string, int> p = iter->second;
    value = p.first;
    return true;
}

std::shared_ptr<ptree> BaseObject::getPtree() const
{
    std::shared_ptr<ptree> pt = std::shared_ptr<ptree>( new ptree );
    for(const string& field: mFields)
    {
        DataMap::const_iterator iter = find(field);
        std::pair<string, int> p = iter->second;
        if(p.second == Types::INTEGER)
        {
            int value = get(field, int{});
            pt->add<int>(field, value);
        }
        else if(p.second == Types::FLOAT)
        {
            float value = get(field, float{});
            pt->add<float>(field, value);
        }
        else if(p.second == Types::STRING)
        {
            string value = get(field, string{});
            pt->add<string>(field, value);
        }
        else if(p.second == Types::OBJECT)
        {
            BaseObject value = get(field, BaseObject{});
            pt->add<string>(field, value);
        }
    }
    return pt;
}

void BaseObject::fromPtree(const ptree &pt)
{
    int id = pt.get<int>(ID_NAME);
    add<int>(ID_NAME, id);
}

std::string BaseObject::toString() const
{
    std::stringstream ss;
    boost::property_tree::write_json(ss, *getPtree(), false);
    return ss.str();
}

void BaseObject::fromString(const string& object)
{
    ptree pt;
    std::stringstream ss;
    ss << object;
    boost::property_tree::json_parser::read_json( ss, pt );
    fromPtree(pt);
}

int BaseObject::getId() const
{
    return get(ID_NAME, -1);
}

void BaseObject::setId(int value)
{
    add<int>(ID_NAME, value);
}

}
