#include "video_note.h"

namespace bot::types {

VideoNote::VideoNote(string& json) : BaseFile() {
    fromString(json);
}

VideoNote::VideoNote(Value const& value) : BaseFile() {
    fillObject(value);
}


void VideoNote::fillDocument(Writer& writer) const {
    writer.Key(fields::LENGTH);
    writer.Int(length);

    writer.Key(fields::DURATION);
    writer.Int(duration);

    if(thumb)
        thumb->asNestedObject(writer);
}

void VideoNote::fillObject(rapidjson::Value const& value) {
    length = value[fields::LENGTH].GetInt();
    duration = value[fields::DURATION].GetInt();
    if(value.HasMember(fields::THUMB)) {
        thumb.emplace(PhotoSize(value[fields::THUMB]));
    }
}

}