#include "voice_chat_scheduled.h"

namespace bot::types {

VoiceChatScheduled::VoiceChatScheduled() : BaseObject() {}

VoiceChatScheduled::VoiceChatScheduled(string& json) : BaseObject() {
    fromString(json);
}

VoiceChatScheduled::VoiceChatScheduled(const Value& value) {
    fillObject(value);
}

VoiceChatScheduled::VoiceChatScheduled(int start_date) : 
    BaseObject(),
    start_date(start_date)
{}

VoiceChatScheduled::~VoiceChatScheduled() {}

void VoiceChatScheduled::fillDocument(Writer& writer) const {
    writer.Key(fields::START_DATE);
    writer.Int(start_date);
}

void VoiceChatScheduled::fillObject(Value const& document) {
    start_date = document[fields::START_DATE].GetInt();
}

}
