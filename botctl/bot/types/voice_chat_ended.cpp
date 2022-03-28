#include "voice_chat_ended.h"

namespace bot::types {

VoiceChatEnded::VoiceChatEnded() : BaseObject() {}

VoiceChatEnded::VoiceChatEnded(string& json) : BaseObject() {
    fromString(json);
}

VoiceChatEnded::VoiceChatEnded(const Value& value) : BaseObject() {
    fillObject(value);
}

VoiceChatEnded::VoiceChatEnded(int duration) : BaseObject(), duration(duration) {}

VoiceChatEnded::~VoiceChatEnded() {}

void VoiceChatEnded::fillDocument(Writer& writer) const {
    writer.Key(fields::DURATION);
    writer.Int(duration);
}

void VoiceChatEnded::fillObject(Value const& document) {
    duration = document[fields::DURATION].GetInt();
}

}