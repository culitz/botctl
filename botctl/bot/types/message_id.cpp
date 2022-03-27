#include "message_id.h"

namespace bot::types
{

MessageId::MessageId(string &json) {
    fromString(json);
}

MessageId::~MessageId() {}

void MessageId::fillDocument(Writer& writer) const {
    writer.Key(MESSAGE_ID.c_str());
    writer.Int(message_id);
}

void MessageId::fillObject(rapidjson::Value const& document) {
    message_id = document[MESSAGE_ID.c_str()].GetInt();
}

}
