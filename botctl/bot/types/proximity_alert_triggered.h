#pragma once
#include "base_object.h"
#include "user.h"
#include "fields.h"

namespace bot::types {

class ProximityAlertTriggered : public BaseObject {
public:
    /// User that triggered the alert
    User traveler;
    /// User that set the alert
    User watcher;
    /// The distance between the users
    int distance;

    ProximityAlertTriggered();
    ProximityAlertTriggered(string&);
    ProximityAlertTriggered(const Value&);
    ProximityAlertTriggered(User traveler, User watcher, int distance);
    virtual ~ProximityAlertTriggered();

protected:
    virtual void fillDocument(Writer& writer) const override;
    virtual void fillObject(Value const& document) override;
};

}