#include "voice_chat_participants_invited.h"


namespace bot::types {

VoiceChatParticipantsInvited::VoiceChatParticipantsInvited() : BaseObject() {}

VoiceChatParticipantsInvited::VoiceChatParticipantsInvited(string& json) : BaseObject() {
    fromString(json);
}

VoiceChatParticipantsInvited::VoiceChatParticipantsInvited(const Value& value) : BaseObject() {
    fillObject(value);
}

VoiceChatParticipantsInvited::VoiceChatParticipantsInvited(std::vector<User>& users) : 
    BaseObject(), users(users) {}

VoiceChatParticipantsInvited::~VoiceChatParticipantsInvited() {}

void VoiceChatParticipantsInvited::fillDocument(Writer& writer) const {
    writer.Key(fields::USERS);
    writer.StartArray();
    for(const User& user: users) 
        user.asNestedObject(writer);
    writer.EndArray();
}

void VoiceChatParticipantsInvited::fillObject(Value const& document) {
    const auto user_objects = document[fields::USERS].GetArray();
    for(const auto& user_object : user_objects)
        users.push_back(User(user_object));
}

}
