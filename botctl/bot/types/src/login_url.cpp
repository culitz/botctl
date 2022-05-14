#include "login_url.h"


namespace bot::types {

LoginUrl::LoginUrl() : BaseObject() {}

LoginUrl::LoginUrl(string& json) : BaseObject() {
    fromString(json);
}

LoginUrl::LoginUrl(const Value& value) : BaseObject() {
    fillObject(value);
}

LoginUrl::LoginUrl(
    string url,
    std::optional<string> forward_text,
    std::optional<string> bot_username,
    std::optional<bool> request_write_access
) : 
    BaseObject(), 
    url(url), 
    forward_text(forward_text), 
    bot_username(bot_username), 
    request_write_access(request_write_access) 
{

}

void LoginUrl::fillDocument(Writer& writer) const {
    writer.Key(fields::URL);
    writer.String(url.c_str());

    if(forward_text) {
        writer.Key(fields::FORWARD_TEXT);
        writer.String(forward_text->c_str());
    }

    if(bot_username) {
        writer.Key(fields::BOT_USERNAME);
        writer.String(bot_username->c_str());
    }

    if(request_write_access) {
        writer.Key(fields::REQUEST_WRITE_ACCESS);
        writer.Bool(request_write_access.value());
    }
}

void LoginUrl::fillObject(Value const& document) {
    url = document[fields::URL].GetString();
    forward_text = getOptString(document, fields::FORWARD_TEXT);
    bot_username = getOptString(document, fields::BOT_USERNAME);
    request_write_access = getOptBool(document, fields::REQUEST_WRITE_ACCESS);
}

}
