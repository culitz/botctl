#pragma once
#include <algorithm>
#include "base_object.h"
#include "fields.h"

namespace bot::types {

class KeyboardButtonPollType : public BaseObject {
public:
    std::optional<string> type;
    KeyboardButtonPollType();
    KeyboardButtonPollType(string&);
    KeyboardButtonPollType(const Value&);
    virtual ~KeyboardButtonPollType();
    virtual size_t hash() const;
protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);

    friend bool operator==(const BaseObject& left, const BaseObject& right);
    friend bool operator!=(const BaseObject& left, const BaseObject& right);
};

inline bool operator==(const KeyboardButtonPollType& left, const KeyboardButtonPollType& right) {
    if(left.type && right.type)
        return left.hash() == right.hash();
    return false;
}

inline bool operator!=(const KeyboardButtonPollType& left, const KeyboardButtonPollType& right) {
    if(left.type && right.type)
        return left.hash() != right.hash();
    return true;
}

}