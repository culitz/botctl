#pragma once
#include "menu_button.h"
#include "constants.h"

namespace bot::types {

class MenuButtonCommands : public MenuButton {
public:
    MenuButtonCommands();
    virtual ~MenuButtonCommands() {}
};

}