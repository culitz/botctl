#include "message_auto_delete_timer_changed.h"

namespace bot::types {

MessageAutoDeleteTimerChanged::MessageAutoDeleteTimerChanged() : BaseObject() {}

MessageAutoDeleteTimerChanged::MessageAutoDeleteTimerChanged(string& json) : BaseObject() {
    fromString(json);
}

MessageAutoDeleteTimerChanged::MessageAutoDeleteTimerChanged(const Value& value) : BaseObject() {
    fillObject(value);
}

MessageAutoDeleteTimerChanged::MessageAutoDeleteTimerChanged(int message_auto_delete_time) : 
BaseObject(), message_auto_delete_time(message_auto_delete_time) 
{}

void MessageAutoDeleteTimerChanged::fromNestedObject(Value const& value) {
    fillObject(value);
}

void MessageAutoDeleteTimerChanged::fillDocument(Writer& writer) const {
    writer.Key(fields::MESSAGE_AUTO_DELETE_TIME);
    writer.Int(message_auto_delete_time);
}

void MessageAutoDeleteTimerChanged::fillObject(Value const& document) {
    message_auto_delete_time = document[fields::MESSAGE_AUTO_DELETE_TIME].GetInt();
}

}
