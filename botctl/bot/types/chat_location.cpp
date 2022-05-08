#include "chat_location.h"


namespace bot::types {


ChatLocation::ChatLocation() : BaseObject() {}

ChatLocation::ChatLocation(
    Location location,
    string address
) : BaseObject(), location(location), address(address) {}

ChatLocation::ChatLocation(Value const& value) : BaseObject() {
    fillObject(value);
}

ChatLocation::ChatLocation(string json) : BaseObject() {
    fromString(json);
}

void ChatLocation::fillDocument(Writer& writer) const {
    writer.Key(fields::LOCATION);
    location.asNestedObject(writer);
    writer.Key(fields::ADDRESS);
    writer.String(address.c_str());
}

void ChatLocation::fillObject(Value const& document) {
    location.fromNestedObject(document[fields::LOCATION]);
    address = document[fields::ADDRESS].GetString();
}

}