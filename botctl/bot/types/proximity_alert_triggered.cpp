#include "proximity_alert_triggered.h"

namespace bot::types {

ProximityAlertTriggered::ProximityAlertTriggered() : BaseObject() {}

ProximityAlertTriggered::ProximityAlertTriggered(string& json) {
    fromString(json);
}

ProximityAlertTriggered::ProximityAlertTriggered(const Value& value) {
    fillObject(value);
}

ProximityAlertTriggered::ProximityAlertTriggered(
    User traveler, 
    User watcher, 
    int distance
) : BaseObject(), traveler(traveler), watcher(watcher), distance(distance)
{}

ProximityAlertTriggered::~ProximityAlertTriggered() {}


void ProximityAlertTriggered::fillDocument(Writer& writer) const {
    writer.Key(fields::TRAVELER);
    traveler.asNestedObject(writer);

    writer.Key(fields::WATCHER);
    watcher.asNestedObject(writer);

    writer.Key(fields::DISTANCE);
    writer.Int(distance);
}

void ProximityAlertTriggered::fillObject(Value const& document) {
    traveler.fromNestedObject(document[fields::TRAVELER]);
    watcher.fromNestedObject(document[fields::WATCHER]);
    distance = document[fields::DISTANCE].GetInt();
}

}