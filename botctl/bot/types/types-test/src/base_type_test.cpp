#include <gtest/gtest.h>
#include "base_object.h"
#include "rapidjson/document.h"

namespace test_base_object_type
{

using BaseObject = bot::types::BaseObject;

TEST(type_base_object, initialize)
{
    auto base_object0 = std::shared_ptr<BaseObject>( new BaseObject() );
    auto base_object1 = std::shared_ptr<BaseObject>( new BaseObject(1) );

    ASSERT_NE(base_object0, nullptr);
    ASSERT_NE(base_object1, nullptr);
}

TEST(type_base_object, constructor_with_parameter)
{
    try{
        BaseObject b(1);
        ASSERT_EQ(b.id, 1);
    }catch(std::exception& ex)
    {
        FAIL() << ex.what();
    }
}

TEST(type_base_object, from_string)
{
    std::stringstream ss;
    ss << "{" << "\"id\":" << "1" << "}";
    BaseObject b;
    b.fromString(ss.str());
    ASSERT_EQ(b.id, 1) << ss.str();
}

TEST(type_base_object, to_string)
{
    std::stringstream ss;
    ss << "{" << "\"id\":" << 1 << "}";
    BaseObject b;
    b.fromString(ss.str());
    std::string result = b.toString();

    std::stringstream json;
    json << result;
    rapidjson::Document document1, document2;

    std::string s1 = std::string(json.str());
    std::string s2 = std::string(ss.str());

    document1.Parse(s1.c_str());
    document2.Parse(s2.c_str());
    int id0 = document1[BaseObject::ID_NAME.c_str()].GetInt();
    int id1 = document2[BaseObject::ID_NAME.c_str()].GetInt();
    ASSERT_EQ(id0, id1);
}

}
