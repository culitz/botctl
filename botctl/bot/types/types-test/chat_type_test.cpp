#include <gtest/gtest.h>
#include <boost/property_tree/ptree.hpp>
#include "../chat.h"
#include "../base_object.h"

using BaseObject = bot::types::BaseObject;
using Chat = bot::types::Chat;
using ptree = boost::property_tree::ptree;
using string = std::string;

std::shared_ptr<ptree> testDataSet()
{
    auto pt = std::shared_ptr<ptree>( new ptree );
    pt->add<string>(Chat::TYPE, "test_type");
    pt->add<string>(Chat::TITLE, "test_title");
    pt->add<string>(Chat::USERNAME, "test_username");
    pt->add<string>(Chat::FIRSTNAME, "test_firstname");
    pt->add<string>(Chat::LASTNAME, "test_lastname");
    pt->add<BaseObject>(Chat::PHOTO, BaseObject{});
    pt->add<BaseObject>(Chat::BIO, BaseObject{});
    pt->add<string>(Chat::DESCRIPTION, "test_description");
    pt->add<string>(Chat::INVITE_LINK, "test_invite_link");
    pt->add<BaseObject>(Chat::PINNED_MESSAGE, BaseObject{});
    pt->add<BaseObject>(Chat::PERMISSIONS, BaseObject{});
    pt->add<int>(Chat::SLOW_MODE_DELAY, 5);
    pt->add<int>(Chat::MESSAGE_AUTO_DELETE_TIME, 5);
    pt->add<string>(Chat::STICKER_SET_NAME, "test_sticker_set_name");
    pt->add<bool>(Chat::CAN_SET_STICKER_SET, true);
    pt->add<int>(Chat::LINKED_CHAT_ID, 5);
    pt->add<BaseObject>(Chat::LOCATION, BaseObject{});
    return pt;
}

bool checkDataSet(std::shared_ptr<ptree> pt)
{
    if(pt->get<string>(Chat::TYPE, "") == "")
        return false;

    if(pt->get<string>(Chat::TITLE, "") == "")
        return false;

    if(pt->get<string>(Chat::USERNAME, "") == "")
        return false;

    if(pt->get<string>(Chat::FIRSTNAME, "") == "")
        return false;

    if(pt->get<string>(Chat::LASTNAME, "") == "")
        return false;

//    if(pt->get<BaseObject>(Chat::PHOTO, BaseObject{}))
//        return false;

//    if(pt->get<BaseObject>(Chat::BIO, BaseObject{}))
//        return false;

    if(pt->get<string>(Chat::DESCRIPTION, "") == "")
        return false;

    if(pt->get<string>(Chat::INVITE_LINK, "") == "")
        return false;

//    if(pt->get<BaseObject>(Chat::PINNED_MESSAGE, BaseObject{}))
//        return false;

//    if(pt->get<BaseObject>(Chat::PERMISSIONS, BaseObject{}))
//        return false;

    if(pt->get<int>(Chat::SLOW_MODE_DELAY, -1) == -1)
        return false;

    if(pt->get<int>(Chat::MESSAGE_AUTO_DELETE_TIME, -1) == -1)
        return false;

    if(pt->get<string>(Chat::STICKER_SET_NAME, "") == "")
        return false;

    if(pt->get<bool>(Chat::CAN_SET_STICKER_SET, false) == false)
        return false;

    if(pt->get<int>(Chat::LINKED_CHAT_ID, -1) == -1)
        return false;

//    if(pt->get<BaseObject>(Chat::LOCATION, BaseObject{}))
//        return false;

    return true;
}

TEST(type_chat, initialize)
{
    std::shared_ptr<ptree> pt = testDataSet();
    auto base_object0 = std::shared_ptr<Chat>( new Chat() );
    auto base_object1 = std::shared_ptr<Chat>( new Chat(*pt) );

    ASSERT_NE(base_object0, nullptr);
    ASSERT_NE(base_object1, nullptr);
}

TEST(type_chat, filds)
{
    std::shared_ptr<ptree> pt = testDataSet();
    auto chat = std::shared_ptr<Chat>( new Chat(*pt) );
    bool is_ok = checkDataSet(pt);
    ASSERT_EQ(is_ok, true);
}
