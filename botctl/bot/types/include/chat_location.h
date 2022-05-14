#pragma once
#include "base_object.h"
#include "location.h"
#include "fields.h"

namespace bot::types {


class ChatLocation : public BaseObject {
public:
    ChatLocation();
    ChatLocation(
        Location location,
        string address
    );
    ChatLocation(Value const&);
    ChatLocation(string json);
    virtual ~ChatLocation() {}

    Location location;
    string address;

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};

}