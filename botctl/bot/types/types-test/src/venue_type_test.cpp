#include <gtest/gtest.h>
#include <venue.h>
#include <location.h>

namespace test_type_venue {

TEST(test_type_venue, serialization) {
    bot::types::Location location(1,2,3,4,5,6);
    bot::types::Venue venue0(
        location,
        "title",
        "address",
        "foursquare_id",
        "foursquare_type",
        "google_place_id",	
        "google_place_type"
    );

    std::string json = venue0.toString();
    bot::types::Venue venue1(json);

    ASSERT_EQ(venue0.location.latitude, venue1.location.latitude);
    ASSERT_EQ(venue0.location.longitude, venue1.location.longitude);
    ASSERT_EQ(venue0.title, venue1.title);
    ASSERT_EQ(venue0.address, venue1.address);
    ASSERT_EQ(venue0.foursquare_id, venue1.foursquare_id);
    ASSERT_EQ(venue0.foursquare_type, venue1.foursquare_type);
    ASSERT_EQ(venue0.google_place_id, venue1.google_place_id);
    ASSERT_EQ(venue0.google_place_type, venue1.google_place_type);
}

}
