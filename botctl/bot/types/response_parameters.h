#include "base_object.h"
#include "fields.h"


namespace bot::types {

class ResponseParameters : public BaseObject {
public:
    ResponseParameters();
    ResponseParameters(string& json);
    ResponseParameters(
        std::optional<int> migrate_to_chat_id = {},
        std::optional<int> retry_after = {}
    );
    virtual ~ResponseParameters() {}

    std::optional<int> migrate_to_chat_id;
    std::optional<int> retry_after;

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};

}