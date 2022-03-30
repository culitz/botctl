#pragma once
#include "base_object.h"
#include "fields.h"

namespace bot::types {

class ReplyKeyboardRemove : public BaseObject {
public:
    bool remove_keyboard;
    std::optional<bool> selective;

    ReplyKeyboardRemove();
    ReplyKeyboardRemove(string&);
    ReplyKeyboardRemove(const Value&);
    ReplyKeyboardRemove(
        bool remove_keyboard,
        std::optional<bool> selective
    ); 
    virtual ~ReplyKeyboardRemove();

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};

}