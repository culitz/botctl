#include "location.h"


namespace bot::types {

Location::Location() {}

Location::~Location() {}

Location::Location(string& json) {
    fromString(json);
}

Location::Location(const Value& value) {
    fillObject(value);
}

Location::Location(
    float longitude,
    float latitude,
    std::optional<float> horizontal_accuracy,
    std::optional<int> live_period,
    std::optional<int> heading,
    std::optional<int> proximity_alert_radius
) : 
    BaseObject(), 
    longitude(longitude),
    latitude(latitude),
    horizontal_accuracy(horizontal_accuracy),
    live_period(live_period),
    heading(heading),
    proximity_alert_radius(proximity_alert_radius)
{}


void Location::fillDocument(Writer& writer) const {
    writer.Key(fields::LONGITUDE);
    writer.Double(longitude);

    writer.Key(fields::LATITUDE);
    writer.Double(latitude);

    if(horizontal_accuracy) {
        writer.Key(fields::HORIZONTAL_ACCURACY);
        writer.Double(horizontal_accuracy.value());
    }
    if(live_period) {
        writer.Key(fields::LIVE_PERIOD);
        writer.Int(live_period.value());
    }
    if(heading) {
        writer.Key(fields::HEADING);
        writer.Int(heading.value());
    }
    if(proximity_alert_radius) {
        writer.Key(fields::PROXIMITY_ALERT_RADIUS);
        writer.Int(proximity_alert_radius.value());
    }
}

void Location::fillObject(Value const& document) {
    longitude = document[fields::LONGITUDE].GetFloat();
    latitude = document[fields::LATITUDE].GetFloat();

    if(document.HasMember(fields::HORIZONTAL_ACCURACY)) {
        horizontal_accuracy = document[fields::HORIZONTAL_ACCURACY].GetFloat();
    }

    if(document.HasMember(fields::LIVE_PERIOD)) {
        live_period = document[fields::LIVE_PERIOD].GetInt();
    }

    if(document.HasMember(fields::HEADING)) {
        heading = document[fields::HEADING].GetInt();
    }

    if(document.HasMember(fields::PROXIMITY_ALERT_RADIUS)) {
        proximity_alert_radius = document[fields::PROXIMITY_ALERT_RADIUS].GetInt();
    }
}

void Location::fromNestedObject(Value const& value) {
    fillObject(value);
}

}
