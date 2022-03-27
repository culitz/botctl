#include "base_object.h"
#include "location.h"


namespace bot::types {

class Venue : public BaseObject {
public:
    /// Venue location. Can't be a live location
    Location location;
    /// Name of the venue
    string title;
    /// Address of the venue
    string address;
    /// Foursquare identifier of the venue
    std::optional<string> foursquare_id;
    /// Foursquare type of the venue. (For example, “arts_entertainment/default”, “arts_entertainment/aquarium” or “food/icecream”.)
    std::optional<string> foursquare_type;
    /// Google Places identifier of the venue	
    std::optional<string> google_place_id;	
    /// Google Places type of the venue. (See supported types.)
    std::optional<string> google_place_type;

    Venue();
    Venue(string&);
    Venue(Value const&);
    Venue(
        Location location,
        string title,
        string address,
        std::optional<string> foursquare_id = {},
        std::optional<string> foursquare_type = {},
        std::optional<string> google_place_id = {},	
        std::optional<string> google_place_type = {}
    );

    virtual ~Venue();

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};

} 