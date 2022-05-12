#include "menu_button_web_app.h"


namespace bot::types {

MenuButtonWebApp::MenuButtonWebApp() 
: MenuButton(consts::menu_button::WEB_APP) {}

MenuButtonWebApp::MenuButtonWebApp(string text, WebAppInfo& web_app) 
: MenuButton(consts::menu_button::WEB_APP), text(text), web_app(web_app) {

}

void MenuButtonWebApp::fillDocument(Writer& writer) const {
    Parent::fillDocument(writer);
    writer.Key(fields::TEXT);
    writer.String(text.c_str());
    writer.Key(fields::WEB_APP);
    web_app.asNestedObject(writer);
}

void MenuButtonWebApp::fillObject(Value const& document) {
    Parent::fillObject(document);
    text = document[fields::TEXT].GetString();
    web_app.fromNestedObject(document[fields::WEB_APP]);
}

}