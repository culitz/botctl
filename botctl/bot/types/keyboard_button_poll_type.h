#include "base_object.h"
#include "fields.h"

namespace bot::types {

class KeyboardButtonPollType : public BaseObject {
public:
    std::optional<string> type;
    KeyboardButtonPollType();
    KeyboardButtonPollType(string&);
    KeyboardButtonPollType(const Value&);
    virtual ~KeyboardButtonPollType();
protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};

}