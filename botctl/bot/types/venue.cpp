#include "venue.h"


namespace bot::types {

Venue::Venue() : BaseObject() {}

Venue::~Venue() {}

Venue::Venue(string& value) : BaseObject() {
    fromString(value);
}

Venue::Venue(const Value& value) : BaseObject() {
    fillObject(value);
}

Venue::Venue(
        Location location,
        string title,
        string address,
        std::optional<string> foursquare_id,
        std::optional<string> foursquare_type,
        std::optional<string> google_place_id,	
        std::optional<string> google_place_type
) : 
    BaseObject(),
    location(location),
    title(title),
    address(address),
    foursquare_id(foursquare_id),
    foursquare_type(foursquare_type),
    google_place_id(google_place_id),
    google_place_type(google_place_type)
{}

void Venue::fillDocument(Writer& writer) const {
    writer.Key(fields::LOCATION);
    location.asNestedObject(writer);

    writer.Key(fields::TITLE);
    writer.String(title.c_str());

    writer.Key(fields::ADDRESS);
    writer.String(address.c_str());

    if(foursquare_id) {
        writer.Key(fields::FOURSQUARE_ID);
        writer.String(foursquare_id->c_str());
    }

    if(foursquare_type) {
        writer.Key(fields::FOURSQUARE_TYPE);
        writer.String(foursquare_type->c_str());
    }

    if(google_place_id) {
        writer.Key(fields::GOOGLE_PLACE_ID);
        writer.String(google_place_id->c_str());
    }

    if(google_place_type) {
        writer.Key(fields::GOOGLE_PLACE_TYPE);
        writer.String(google_place_type->c_str());
    }
}

void Venue::fillObject(Value const& document) {
    location.fromNestedObject(document[fields::LOCATION]);
    title = document[fields::TITLE].GetString();
    address = document[fields::ADDRESS].GetString();
    if(document.HasMember(fields::FOURSQUARE_ID))
        foursquare_id = document[fields::FOURSQUARE_ID].GetString();
    if(document.HasMember(fields::FOURSQUARE_TYPE))
        foursquare_type = document[fields::FOURSQUARE_TYPE].GetString();
    if(document.HasMember(fields::GOOGLE_PLACE_ID))
        google_place_id = document[fields::GOOGLE_PLACE_ID].GetString();
    if(document.HasMember(fields::GOOGLE_PLACE_TYPE))
        google_place_type = document[fields::GOOGLE_PLACE_TYPE].GetString();
}

} 
