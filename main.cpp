#include <sstream>
#include <iostream>
#include "botctl/bot/types/venue.h"
#include "botctl/bot/types/location.h"

using namespace bot::types;


int main()
{
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
    std::cout << json << std::endl;
    bot::types::Venue venue1(json); 
}
