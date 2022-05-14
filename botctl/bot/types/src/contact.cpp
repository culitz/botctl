#include "contact.h"

namespace bot::types {


void Contact::fillDocument(Writer& writer) const {
    writer.Key(fields::PHONE_NUMBER);
    writer.String(phone_number.c_str());

    writer.Key(fields::FIRST_NAME);
    writer.String(first_name.c_str());

    if(last_name) {
        writer.Key(fields::LAST_NAME);
        writer.String(last_name->c_str());
    }
    if(user_id) {
        writer.Key(fields::USER_ID);
        writer.Int(*user_id);
    }
    if(vcard) {
        writer.Key(fields::VCARD);
        writer.String(vcard->c_str());
    }
}

void Contact::fillObject(Value const& value) {
    phone_number = value[fields::PHONE_NUMBER].GetString();
    first_name = value[fields::FIRST_NAME].GetString();
    if(value.HasMember(fields::LAST_NAME))
        last_name = value[fields::LAST_NAME].GetString();
    
    if(value.HasMember(fields::USER_ID))
        user_id = value[fields::USER_ID].GetInt();

    if(value.HasMember(fields::VCARD))
        vcard = value[fields::VCARD].GetString();
}

}
