#include "photo_size.h"

namespace bot::types {

PhotoSize::PhotoSize(string &json) : BaseFile()
{
    fromString(json);
}

void PhotoSize::fillDocument(Writer &writer) const
{
    Parent::fillDocument(writer);
    writer.Key(WIDTH.c_str());
    writer.Int(width);

    writer.Key(HEIGHT.c_str());
    writer.Int(height);
}

void PhotoSize::fillObject(rapidjson::Document &document)
{
    Parent::fillObject(document);
    width = document[WIDTH.c_str()].GetInt();
    height = document[HEIGHT.c_str()].GetInt();
}

}
