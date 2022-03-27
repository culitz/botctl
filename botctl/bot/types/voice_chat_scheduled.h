#include "base_object.h"
#include "fields.h"


namespace bot::types {

class VoiceChatScheduled : public BaseObject {
public:
    int start_date; 
    VoiceChatScheduled();
    VoiceChatScheduled(string&);
    VoiceChatScheduled(const Value&);
    VoiceChatScheduled(int);
    virtual ~VoiceChatScheduled();
protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};

}