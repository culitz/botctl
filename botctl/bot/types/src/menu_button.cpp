#include "menu_button.h"


namespace bot::types {

MenuButton::MenuButton(string type) : BaseObject(), type(type) {}

MenuButton::MenuButton() : BaseObject() {}


void MenuButton::fillDocument(Writer& writer) const {
    writer.Key(fields::TYPE);
    writer.String(type.c_str());
}

void MenuButton::fillObject(Value const& document) {
    type = document[fields::TYPE].GetString();
}


}
