#include "poll_answer.h"

namespace bot::types {

PollAnswer::PollAnswer() : BaseObject() {}
PollAnswer::~PollAnswer() {}

PollAnswer::PollAnswer(Value const& value) {
    fillObject(value);
}

PollAnswer::PollAnswer(string& json) : BaseObject() {
    fromString(json);
}

void PollAnswer::fillDocument(Writer& writer) const {
    writer.Key(fields::POOL_ID);
    writer.String(poll_id.c_str());

    writer.Key(fields::USER);
    user.asNestedObject(writer);

    writer.Key(fields::OPTION_IDS);
    writer.StartArray();
    for(int array_item : option_ids)
        writer.Int(array_item);
    writer.EndArray();
}

void PollAnswer::fillObject(rapidjson::Value const& document) {
    poll_id = document[fields::POOL_ID].GetString();
    
    if(document.HasMember(fields::USER)) {
        const Value& object = document[fields::USER];
        user.fromNestedObject(object);
    }

    auto array = document[fields::OPTION_IDS].GetArray();
    for(const auto& array_item : array) {
        option_ids.push_back(array_item.GetInt());
    }
}

}
