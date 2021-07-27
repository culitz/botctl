#include <gtest/gtest.h>
#include <boost/property_tree/ptree.hpp>
#include "../base_object.h"

using BaseObject = bot::types::BaseObject;
using ptree = boost::property_tree::ptree;

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
        ASSERT_EQ(b.getId(), 1);
    }catch(std::exception& ex)
    {
        FAIL() << ex.what();
    }
}

TEST(type_base_object, from_property_tree)
{
    ptree pt;
    pt.add<int>(BaseObject::ID_NAME, 1);
    BaseObject b;
    b.fromPtree(pt);
    ASSERT_EQ(b.getId(), 1);
}

TEST(type_base_object, get_ptree)
{
    BaseObject b(1);
    std::shared_ptr<ptree> pt = b.getPtree();
    int id = pt->get<int>(BaseObject::ID_NAME);
    ASSERT_EQ(id, 1);
}

TEST(type_base_object, from_string)
{
    std::stringstream ss;
    ss << "{" << "\"id\":" << "1" << "}";
    BaseObject b;
    b.fromString(ss.str());
    ASSERT_EQ(b.getId(), 1) << ss.str();
}

TEST(type_base_object, to_string)
{
    std::stringstream ss;
    ss << "{" << "\"id\":" << 1 << "}";
    BaseObject b;
    b.fromString(ss.str());
    std::string result = b.toString();
    std::string err_msg = ss.str() + " not equal " + result;

    std::stringstream json;
    json << result;
    ptree pt0, pt1;
    boost::property_tree::read_json(ss, pt0);
    boost::property_tree::read_json(json, pt1);
    int id0 = pt0.get<int>(BaseObject::ID_NAME);
    int id1 = pt1.get<int>(BaseObject::ID_NAME);
    ASSERT_EQ(id0, id1) << err_msg;
}

TEST(type_base_object, add_int)
{
    int value0 = 22;
    std::string field = "f";
    BaseObject b;
    b.add<int>(field, value0);
    int value1 = b.get(field, 0);
    ASSERT_EQ(value0, value1);
}

TEST(type_base_object, add_float)
{
    double value0 = 22;
    std::string field = "f";
    float dv = 0;
    BaseObject b;
    b.add<float>(field, value0);
    float value1 = b.get(field, dv);
    ASSERT_EQ(value0, value1);
}

TEST(type_base_object, add_string)
{
    std::string value0 = "22";
    std::string field = "f";
    BaseObject b;
    b.add<std::string>(field, value0);
    std::string value1 = b.get(field, std::string{0});
    ASSERT_EQ(value0, value1);
}

TEST(type_base_object, add_baseobject)
{
    BaseObject child(1);
    std::string field = "f";

    BaseObject parent;
    parent.add<BaseObject>(field, child);

    BaseObject child_result = parent.get(field, BaseObject{0});
    ASSERT_EQ(child.getId(), child_result.getId());
}

TEST(type_base_object, using_opt_int)
{
    int value0 = 22;
    std::string field = "f";

    BaseObject b;
    b.add<int>(field, value0);

    std::optional<int> opt_val = b.get<int>(field);
    ASSERT_EQ(value0, opt_val.value());
}

TEST(type_base_object, using_opt_double)
{
    double value0 = 22.0;
    std::string field = "f";

    BaseObject b;
    b.add<double>(field, value0);

    std::optional<double> opt_val = b.get<double>(field);
    ASSERT_EQ(value0, opt_val.value());
}

TEST(type_base_object, using_opt_string)
{
    std::string value0 = "22";
    std::string field = "f";

    BaseObject b;
    b.add<std::string>(field, value0);

    std::optional<std::string> opt_val = b.get<std::string>(field);
    ASSERT_EQ(value0, opt_val.value());
}

TEST(type_base_object, equal_test)
{
    auto b0 = std::shared_ptr<BaseObject>( new BaseObject{0} );
    auto b1 = std::shared_ptr<BaseObject>( new BaseObject{0} );
    auto b2 = std::shared_ptr<BaseObject>( new BaseObject{1} );

    bool is_eq = (*b0 == *b1);
    bool is_ne = (*b0 != *b2);
    ASSERT_EQ(is_eq, true) << b0->hash() << " " << b1->hash();
    ASSERT_EQ(is_ne, true) << b0->hash() << " " << b2->hash();;
}
