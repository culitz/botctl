#include "force_reply.h"

namespace bot::types {

ForceReply::ForceReply() : BaseObject() {

}

ForceReply::~ForceReply() {}

ForceReply::ForceReply(std::string &json) : BaseObject() {
    fromString(json);
}

ForceReply::ForceReply(const Value &document) : BaseObject() {
    fromNestedObject(document);
}

ForceReply::ForceReply(
        bool force_reply,
        std::optional<std::string> input_field_placeholder,
        std::optional<bool> selective
) : BaseObject(),
    force_reply(force_reply),
    input_field_placeholder(input_field_placeholder),
    selective(selective)
{

}

void ForceReply::fillDocument(Writer &writer) const {
    writer.Key(fields::FORCE_REPLY);
    writer.Bool(force_reply);

    if(input_field_placeholder) {
        writer.Key(fields::INPUT_FIELD_PLACEHOLDER);
        writer.String(input_field_placeholder->c_str());
    }

    if(selective) {
        writer.Key(fields::SELECTIVE);
        writer.Bool(*selective);
    }
}

void ForceReply::fillObject(Value const& document) {
    force_reply = document[fields::FORCE_REPLY].GetBool();
    input_field_placeholder = getOptString(document, fields::INPUT_FIELD_PLACEHOLDER);
    selective = getOptBool(document, fields::SELECTIVE);
}

}
