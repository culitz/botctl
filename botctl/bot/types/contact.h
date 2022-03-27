#pragma once
#include "base_object.h"
#include "fields.h"


namespace bot::types {


class Contact : public BaseObject {
public:
    /// Contact's phone number
    string phone_number;
    
    /// Contact's first name
    string first_name;
    
    /// Contact's last name
    std::optional<string> last_name;

    /// Contact's user identifier in Telegram. This number may have more than 32 
    /// significant bits and some programming languages may have difficulty/silent 
    /// defects in interpreting it. But it has at most 52 significant bits, so a 
    /// 64-bit integer or double-precision float type are safe for storing this identifier.	
    std::optional<int> user_id;

    /// Additional data about the contact in the form of a vCard
    std::optional<string> vcard;
    
    Contact() : BaseObject() {}
    Contact(string& json) : BaseObject() {fromString(json);}
    Contact(Value const& value) : BaseObject(value) {}
    virtual ~Contact() {}
protected:
    virtual void fillDocument(Writer& writer) const override;
    virtual void fillObject(Value const& document) override;
};

}