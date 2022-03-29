#include <vector>
#include <gtest/gtest.h>
#include "../user.h"
#include "../user_profile_photos.h"
#include "../photo_size.h"


namespace test_user_profile_photo {

using namespace bot::types;

TEST(user_profile_photo_type_test, serialization) {
    std::vector<PhotoSize> photos {
        PhotoSize(200, 200),
        PhotoSize(300, 300)
    };

    UserProfilePhotos object0(2, photos);
    std::string json = object0.toString();
    UserProfilePhotos object1(json);

    ASSERT_EQ(object0.total_count, object1.total_count);
    for(int i = 0; i < photos.size(); i++) {
        ASSERT_EQ(object0.photos[i].width, object1.photos[i].width);
        ASSERT_EQ(object0.photos[i].height, object1.photos[i].height);
    }
}

}