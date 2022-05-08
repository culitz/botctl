#pragma once
#include "base_object.h"
#include "fields.h"


namespace bot::types {

class BotCommand : public BaseObject {
public:
    BotCommand();
    BotCommand(string command, string description);
    BotCommand(string& json);
    BotCommand(Value const& value);
    virtual ~BotCommand() {}

    string command;
    string description;

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};


}