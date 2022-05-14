#include "poll_options.h"

namespace bot::types {

PollOption::PollOption(string& json) : BaseObject() {
    fromString(json);
}

PollOption::PollOption(Value const& value) : BaseObject() {
    fillObject(value);
}

PollOption::PollOption(string text, int voter_count) : 
    BaseObject(), 
    text(text), 
    voter_count(voter_count) {}

void PollOption::fillDocument(Writer& writer) const {
    writer.Key(fields::TEXT);
    writer.String(text.c_str());

    writer.Key(fields::VOTER_COUNT);
    writer.Int(voter_count);
}

void PollOption::fillObject(rapidjson::Value const& document) {
    text = document[fields::TEXT].GetString();
    voter_count = document[fields::VOTER_COUNT].GetInt();
}

}
