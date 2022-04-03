#include "base_object.h"
#include "fields.h"


namespace bot::types {

class LoginUrl : public BaseObject {
public:
    string url;
    std::optional<string> forward_text;
    std::optional<string> bot_username;
    std::optional<bool> request_write_access;

    LoginUrl();
    LoginUrl(string&);
    LoginUrl(const Value&);
    LoginUrl(
        string url,
        std::optional<string> forward_text,
        std::optional<string> bot_username,
        std::optional<bool> request_write_access
    );

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};

}