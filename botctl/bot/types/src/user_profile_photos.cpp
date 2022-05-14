#include "user_profile_photos.h"

namespace bot::types {

UserProfilePhotos::UserProfilePhotos() : BaseObject() {}

UserProfilePhotos::UserProfilePhotos(string& json) : BaseObject() {
    fromString(json);
}

UserProfilePhotos::UserProfilePhotos(const Value& value) : BaseObject() {
    fillObject(value);
}

UserProfilePhotos::UserProfilePhotos(int total_count, std::vector<PhotoSize>& photos) :
    BaseObject(), total_count(total_count), photos(photos) {}

UserProfilePhotos::~UserProfilePhotos() {}

void UserProfilePhotos::fillDocument(Writer& writer) const {
    writer.Key(fields::TOTAL_COUNT);
    writer.Int(total_count);

    writer.Key(fields::PHOTOS);
    writer.StartArray();
    for(const PhotoSize& photo: photos)
        photo.asNestedObject(writer);
    writer.EndArray();
}

void UserProfilePhotos::fillObject(Value const& document) {
    total_count = document[fields::TOTAL_COUNT].GetInt();
    for(const auto& array_item : document[fields::PHOTOS].GetArray()) 
        photos.push_back(PhotoSize(array_item));
}

}
