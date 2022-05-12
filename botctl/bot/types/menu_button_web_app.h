#pragma once
#include "menu_button.h"
#include "constants.h"
#include "web_app_info.h"
#include "fields.h"

namespace bot::types {


class MenuButtonWebApp : public MenuButton {
public:
    typedef MenuButton Parent;
    MenuButtonWebApp();
    MenuButtonWebApp(string text, WebAppInfo& web_app);
    virtual ~MenuButtonWebApp() {}

    string text;
    WebAppInfo web_app;

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};

}