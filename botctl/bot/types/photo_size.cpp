#include "photo_size.h"

namespace bot::types {

PhotoSize::PhotoSize(string &json) : BaseFile() {
    fromString(json);
}

PhotoSize::PhotoSize(Value const& value) {
    fillObject(value);
}

void PhotoSize::fillDocument(Writer &writer) const {
    Parent::fillDocument(writer);
    writer.Key(WIDTH.c_str());
    writer.Int(width);

    writer.Key(HEIGHT.c_str());
    writer.Int(height);
}

void PhotoSize::fillObject(rapidjson::Value const &value) {
    BaseFile::fillObject(value);
    width = value[WIDTH.c_str()].GetInt();
    height = value[HEIGHT.c_str()].GetInt();
}

}
