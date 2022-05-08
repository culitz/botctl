#pragma once
#include "base_object.h"
#include "fields.h"


namespace bot::types {

class BotCommandScope : public BaseObject {
public:
    BotCommandScope();
    BotCommandScope(string& json);
    BotCommandScope(Value const& value);
    
    string type;

protected:
    virtual void fillDocument(Writer& writer) const override;
    virtual void fillObject(Value const& document) override;
};

}