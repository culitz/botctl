#include "chat_photo.h"

namespace bot::types {

ChatPhoto::ChatPhoto() : BaseObject() {}

ChatPhoto::ChatPhoto(std::string& json) : BaseObject() {
    fromString(json);
}

ChatPhoto::ChatPhoto(Value const& document) : BaseObject() {
    fromNestedObject(document);
}

ChatPhoto::ChatPhoto(
    std::string small_file_id,
    std::string small_file_unique_id,
    std::string big_file_id,
    std::string big_file_unique_id
) : BaseObject(),
    small_file_id(small_file_id),
    small_file_unique_id(small_file_unique_id),
    big_file_id(big_file_id),
    big_file_unique_id(big_file_unique_id)
{}

ChatPhoto::~ChatPhoto() {}

void ChatPhoto::fillDocument(Writer& writer) const {
    writer.Key(fields::SMALL_FILE_ID);
    writer.String(small_file_id.c_str());

    writer.Key(fields::SMALL_FILE_UNIQUE_ID);
    writer.String(small_file_unique_id.c_str());

    writer.Key(fields::BIG_FILE_ID);
    writer.String(big_file_id.c_str());

    writer.Key(fields::BIG_FILE_UNIQUE_ID);
    writer.String(big_file_unique_id.c_str());
}

void ChatPhoto::fillObject(Value const& document) {
    small_file_id = document[fields::SMALL_FILE_ID].GetString();
    small_file_unique_id = document[fields::SMALL_FILE_UNIQUE_ID].GetString();
    big_file_id = document[fields::BIG_FILE_ID].GetString();
    big_file_unique_id = document[fields::BIG_FILE_UNIQUE_ID].GetString();
}

}