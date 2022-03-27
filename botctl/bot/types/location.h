#pragma once
#include "base_object.h"
#include "fields.h"

namespace bot::types {

class Location : public BaseObject {
public:
    /// Longitude as defined by sender
    float longitude;
    /// Latitude as defined by sender
    float latitude;
    /// The radius of uncertainty for the location, measured in meters; 0-1500
    std::optional<float> horizontal_accuracy;
    /// Time relative to the message sending date, during which the location can 
    /// be updated; in seconds. For active live locations only.
    std::optional<int> live_period;
    /// The direction in which user is moving, in degrees; 1-360. For active live locations only.
    std::optional<int> heading;
    /// Maximum distance for proximity alerts about approaching another chat member, in meters. 
    /// For sent live locations only.
    std::optional<int> proximity_alert_radius;

    Location();
    Location(string&);
    Location(const Value&);
    Location(
        float longitude,
        float latitude,
        std::optional<float> horizontal_accuracy = {},
        std::optional<int> live_period = {},
        std::optional<int> heading = {},
        std::optional<int> proximity_alert_radius = {}
    );
    virtual ~Location();

    virtual void fromNestedObject(Value const& value) override;
protected:
    virtual void fillDocument(Writer& writer) const override;
    virtual void fillObject(Value const& document) override;
};

}