#include "animation.h"

namespace bot::types
{

Animation::Animation(string& json) : BaseFile()
{
    fromString(json);
}

void Animation::fillDocument(Writer& writer) const
{
    BaseFile::fillDocument(writer);
    writer.Key(WIDTH.c_str());
    writer.Int(widght);
    writer.Key(HEIGHT.c_str());
    writer.Int(heght);
    writer.Key(DUARATION.c_str());
    
    if(thumb)
        thumb->asNestedObject(writer);
}

void Animation::fillObject(rapidjson::Document& document)
{
    BaseFile::fillObject(document);
    widght = document[WIDTH.c_str()].GetInt();
    heght = document[HEIGHT.c_str()].GetInt();
    duaration = document[DUARATION.c_str()].GetInt();
    if(thumb)
    {
        PhotoSize photo_size;
        photo_size.fromNestedObject(document);
        thumb.emplace(photo_size);
    }
}

}