#pragma once
#include "fields.h"
#include "base_object.h"

namespace bot::types {

class MessageAutoDeleteTimerChanged : public BaseObject {
public:
    int message_auto_delete_time; 
    MessageAutoDeleteTimerChanged();
    MessageAutoDeleteTimerChanged(string&);
    MessageAutoDeleteTimerChanged(const Value&);
    MessageAutoDeleteTimerChanged(int);

    virtual void fromNestedObject(Value const& value) override;
protected:
    virtual void fillDocument(Writer& writer) const override;
    virtual void fillObject(Value const& document) override;
};

}