#pragma once
#include <vector>
#include "base_object.h"
#include "fields.h"
#include "photo_size.h"

namespace bot::types {

class UserProfilePhotos : public BaseObject {
public:
    int total_count;
    std::vector<PhotoSize> photos;

    UserProfilePhotos();
    UserProfilePhotos(string&);
    UserProfilePhotos(const Value&);
    UserProfilePhotos(int, std::vector<PhotoSize>&);
    virtual ~UserProfilePhotos();

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
}; 

}