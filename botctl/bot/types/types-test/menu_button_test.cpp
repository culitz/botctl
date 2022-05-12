#include <gtest/gtest.h>
#include "../constants.h"
#include "../menu_button.h"
#include "../menu_button_commands.h"
#include "../menu_button_default.h"
#include "../menu_button_web_app.h"
#include "../web_app_info.h"

namespace menu_button_test {

using namespace std;
using namespace bot::types;

string type = "type";
MenuButton btn0(type);

TEST(menu_button_test, serialize) {
    string json = btn0.toString();
    MenuButton btn1;
    btn1.fromString(json);
    ASSERT_EQ(btn1.type, type);
}


TEST(menu_button_test, type_default) {
    MenuButtonDefault btn;
    ASSERT_EQ(btn.type, consts::menu_button::DEFAULT);
}

TEST(menu_button_test, type_web_app) {
    MenuButtonWebApp btn;
    ASSERT_EQ(btn.type, consts::menu_button::WEB_APP);
}

TEST(menu_button_test, type_commands) {
    MenuButtonCommands btn;
    ASSERT_EQ(btn.type, consts::menu_button::COMMANDS);
}


TEST(menu_button_test, type_web_app_serialize) {
    WebAppInfo info;
    info.url = "https://localhost:8000";
    MenuButtonWebApp app0("text", info);

    string json = app0.toString();
    MenuButtonWebApp app1;
    app1.fromString(json);
    ASSERT_EQ(app1.type, app0.type);
    ASSERT_EQ(app1.web_app.url, app0.web_app.url);
    ASSERT_EQ(app1.text, app0.text);
}

}