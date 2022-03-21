#include "voice.h"


namespace bot::types {

Voice::Voice(string& json) : BaseFile() {
    fromString(json);
}

Voice::Voice(Value const& value) {
    fillObject(value);
}

void Voice::fillDocument(Writer& writer) const {
    BaseFile::fillDocument(writer);
    writer.Key(fields::DURATION);
    writer.Int(duration);
}

void Voice::fillObject(rapidjson::Value const& value) {
    BaseFile::fillObject(value);
    duration = value[fields::DURATION].GetInt();
}

}