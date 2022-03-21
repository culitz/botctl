#include "animation.h"

namespace bot::types
{

Animation::Animation(string& json) : BaseFile() {
    fromString(json);
}

void Animation::fillDocument(Writer& writer) const {
    BaseFile::fillDocument(writer);
    writer.Key(fields::WIDTH);
    writer.Int(widght);
    writer.Key(fields::HEIGHT);
    writer.Int(heght);
    writer.Key(fields::DURATION);
    
    if(thumb)
        thumb->asNestedObject(writer);
}

void Animation::fillObject(rapidjson::Value const& document) {
    BaseFile::fillObject(document);
    widght = document[fields::WIDTH].GetInt();
    heght = document[fields::HEIGHT].GetInt();
    duaration = document[fields::DURATION].GetInt();
    if(thumb) {
        PhotoSize photo_size;
        photo_size.fromNestedObject(document);
        thumb.emplace(photo_size);
    }
}

}