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
    bool is_ok = checkDataSet(chat->getPtree());
    ASSERT_EQ(is_ok, true);
}

TEST(type_chat, get_type)
{
    std::shared_ptr<ptree> pt = testDataSet();
    Chat* chat = new Chat(*pt);

    string type = pt->get<string>(Chat::TYPE, "");
    if(type != chat->getType())
        FAIL() << type << " != " << chat->getType();
    delete chat;
}

TEST(type_chat, get_title)
{
    std::shared_ptr<ptree> pt = testDataSet();
    Chat* chat = new Chat(*pt);

    string title = pt->get<string>(Chat::TITLE, "");
    string chat_title = chat->getTitle().value();
    if(title != chat_title)
        FAIL() << title << " != " << chat_title;
    delete chat;
}

TEST(type_chat, get_username)
{
    std::shared_ptr<ptree> pt = testDataSet();
    Chat* chat = new Chat(*pt);

    string username = pt->get<string>(Chat::USERNAME, "");
    string chat_username = chat->getUsername().value();
    if(username != chat_username)
        FAIL() << username << " != " << chat_username;
    delete chat;
}

TEST(type_chat, get_firstname)
{
    std::shared_ptr<ptree> pt = testDataSet();
    Chat* chat = new Chat(*pt);

    string firstname = pt->get<string>(Chat::FIRSTNAME, "");
    string chat_firstname = chat->getFirstName().value();
    if(firstname != chat_firstname)
        FAIL() << firstname << " != " << chat_firstname;

    delete chat;
}

TEST(type_chat, get_lastname)
{
    std::shared_ptr<ptree> pt = testDataSet();
    Chat* chat = new Chat(*pt);

    string lastname = pt->get<string>(Chat::LASTNAME, "");
    string chat_lastname = chat->getLastName().value();
    if(lastname != chat_lastname)
        FAIL() << lastname << " != " << chat_lastname;

    delete chat;
}

TEST(type_chat, get_photo)
{
    std::shared_ptr<ptree> pt = testDataSet();
    Chat* chat = new Chat(*pt);

//    if(pt->get<BaseObject>(Chat::PHOTO, BaseObject{}))
//        return false;

    delete chat;
}

TEST(type_chat, get_bio)
{
    std::shared_ptr<ptree> pt = testDataSet();
    Chat* chat = new Chat(*pt);

//    if(pt->get<BaseObject>(Chat::BIO, BaseObject{}))
//        return false;

    delete chat;
}

TEST(type_chat, get_description)
{
    std::shared_ptr<ptree> pt = testDataSet();
    Chat* chat = new Chat(*pt);

    string descr = pt->get<string>(Chat::DESCRIPTION, "");
    string chat_descr = chat->getDescription().value();
    if(descr != chat_descr)
        FAIL() << descr << " != " << chat_descr;

    delete chat;
}

TEST(type_chat, get_invite_link)
{
    std::shared_ptr<ptree> pt = testDataSet();
    Chat* chat = new Chat(*pt);

    string inv_link = pt->get<string>(Chat::INVITE_LINK, "");
    string chat_inv_link = chat->getInviteLink().value();
    if(inv_link != chat_inv_link)
        FAIL() << inv_link << " != " << chat_inv_link;

    delete chat;
}

TEST(type_chat, get_pinned_message)
{
    std::shared_ptr<ptree> pt = testDataSet();
    Chat* chat = new Chat(*pt);

//    if(pt->get<BaseObject>(Chat::PINNED_MESSAGE, BaseObject{}))
//        return false;

    delete chat;
}

TEST(type_chat, get_permissions)
{
    std::shared_ptr<ptree> pt = testDataSet();
    Chat* chat = new Chat(*pt);

//    if(pt->get<BaseObject>(Chat::PERMISSIONS, BaseObject{}))
//        return false;
    delete chat;
}

TEST(type_chat, get_slow_mode_delay)
{
    std::shared_ptr<ptree> pt = testDataSet();
    Chat* chat = new Chat(*pt);

    int smd = pt->get<int>(Chat::SLOW_MODE_DELAY, -1);
    int chat_smd = chat->getSlowModeDelay().value();
    if( smd != chat_smd)
         FAIL() << smd << " != " << chat_smd;

    delete chat;
}

TEST(type_chat, get_message_auto_delete)
{
    std::shared_ptr<ptree> pt = testDataSet();
    Chat* chat = new Chat(*pt);

    int madt = pt->get<int>(Chat::MESSAGE_AUTO_DELETE_TIME, -1);
    int chat_madt = chat->getMessageAutoDeleteTime().value();
    if(madt != chat_madt)
        FAIL() << madt << " != " << chat_madt;

    delete chat;
}

TEST(type_chat, get_sticker_set_name)
{
    std::shared_ptr<ptree> pt = testDataSet();
    Chat* chat = new Chat(*pt);

    string ssn = pt->get<string>(Chat::STICKER_SET_NAME, "");
    string chat_ssn = chat->getStickerSetName().value();
    if(ssn != chat_ssn)
        FAIL() << ssn << " != " << chat_ssn;

    delete chat;
}

TEST(type_chat, get_can_set_sticker_name)
{
    std::shared_ptr<ptree> pt = testDataSet();
    Chat* chat = new Chat(*pt);

    bool can_ssn = pt->get<bool>(Chat::CAN_SET_STICKER_SET, false);
    bool chat_can_ssn = chat->getCanSetStickerSet().value();
    if(can_ssn != chat_can_ssn)
        FAIL() << can_ssn << " != " << chat_can_ssn;

    delete chat;
}

TEST(type_chat, get_linked_chat_id)
{
    std::shared_ptr<ptree> pt = testDataSet();
    Chat* chat = new Chat(*pt);

    int link_chat_id = pt->get<int>(Chat::LINKED_CHAT_ID, -1);
    int chat_link_chat_id = chat->getLinkedChatId().value();
    if(link_chat_id != chat_link_chat_id)
        FAIL() << link_chat_id << " != " << chat_link_chat_id;

    delete chat;
}

TEST(type_chat, get_location)
{
    std::shared_ptr<ptree> pt = testDataSet();
    Chat* chat = new Chat(*pt);

//    if(pt->get<BaseObject>(Chat::LOCATION, BaseObject{}))
//        return false;

    delete chat;
}
