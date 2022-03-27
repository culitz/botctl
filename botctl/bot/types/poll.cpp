#include "poll.h"


namespace bot::types {

Poll::Poll() {}
Poll::~Poll() {}

Poll::Poll(string& json) : BaseObject() {
    fromString(json);
}

Poll::Poll(const Value& value) {
    fillObject(value);
}

void Poll::fillDocument(Writer& writer) const {
    
}

void Poll::fillObject(Value const& document) {
    id = document[fields::ID].GetString();
    question = document[fields::QUESTION].GetString();

    auto poll_opt_array = document[fields::OPTIONS].GetArray();
    for(const auto& array_item: poll_opt_array) {
        options.push_back(PollOption(array_item));
    }

    total_voter_count = document[fields::TOTAL_VOITER_COUNT].GetInt();
    is_closed = document[fields::IS_CLOSED].GetBool();
    is_anonymous = document[fields::IS_ANONYMOUS].GetBool();
    type = document[fields::TYPE].GetString();
    allows_multiple_answers = document[fields::ALLOW_MULTIPLE_ANSWERS].GetBool();

    correct_option_id = getOptInt(document, fields::CORRECT_OPTION_ID);
    explanation = getOptString(document, fields::EXPLANATION);

    if(document.HasMember(fields::EXPLANATION_ENTITIES)) {
        std::vector<MessageEntity> msg_entities;
        auto exp_array = document[fields::EXPLANATION_ENTITIES].GetArray();
        for(const auto& array_item: exp_array) {
            msg_entities.push_back(MessageEntity(array_item));
        }
        explanation_entities.emplace(msg_entities);
    }

    open_period = getOptInt(document, fields::OPEN_PERIOD);
    close_date = getOptInt(document, fields::CLOSE_DATE);
}


}