#include "base_object.h"


namespace bot::types {

class KeyboardButton : public BaseObject {
public:
    string text;
    std::optional<bool> request_contact;
    std::optional<bool> request_location;
    /// \todo change to KeyboardButtonPollType
    std::optional<BaseObject> request_poll;

    KeyboardButton();
    KeyboardButton(string&);
    KeyboardButton(const Value&);
    KeyboardButton(
        string& text,
        std::optional<bool> request_contact,
        std::optional<bool> request_location,
        std::optional<BaseObject> request_poll
    );

    virtual ~KeyboardButton();
};


}