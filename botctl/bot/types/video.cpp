#include "video.h"
#include "fields.h"

namespace bot::types {

Video::Video(string& json) : BaseFile(json) {
    fromString(json);
}

Video::Video(Value const& value) : BaseFile() {
    fillObject(value);
}

void Video::fillDocument(Writer& writer) const {
    BaseFile::fillDocument(writer);
    writer.Key(fields::WIDTH);
    writer.Int(width);

    writer.Key(fields::HEIGHT);
    writer.Int(height);

    writer.Key(fields::DURATION);
    writer.Int(duration);

    if(thumb)
        thumb->asNestedObject(writer);
}

void Video::fillObject(rapidjson::Value const& value) {
    width = value[fields::WIDTH].GetInt();
    height = value[fields::HEIGHT].GetInt();
    duration = value[fields::DURATION].GetInt();

    if(value.HasMember(fields::THUMB))
        thumb.emplace(PhotoSize(value[fields::THUMB]));
}

} // namespace name
