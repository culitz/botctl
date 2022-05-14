#include "response_parameters.h"

namespace bot::types {

ResponseParameters::ResponseParameters() : BaseObject() {}

ResponseParameters::ResponseParameters(string& json) {
    fromString(json);
}

ResponseParameters::ResponseParameters(
    std::optional<int> migrate_to_chat_id,
    std::optional<int> retry_after
) : BaseObject(), 
    migrate_to_chat_id(migrate_to_chat_id), 
    retry_after(retry_after) {}


void ResponseParameters::fillDocument(Writer& writer) const {
    writer.Key(fields::MIGRATE_TO_CHAT_ID);
    writer.Int(*migrate_to_chat_id);
    writer.Key(fields::RETRY_AFTER);
    writer.Int(*retry_after);
}

void ResponseParameters::fillObject(Value const& document) {
    migrate_to_chat_id = document[fields::MIGRATE_TO_CHAT_ID].GetInt();
    retry_after = document[fields::RETRY_AFTER].GetInt();
}

}
