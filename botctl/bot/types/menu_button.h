#pragma once
#include "base_object.h"
#include "fields.h"


namespace bot::types {

class MenuButton : public BaseObject {
public:
    MenuButton();
    MenuButton(string type);
    virtual ~MenuButton() {}

    string type;

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};

}