#include "base_file.h"
#include "fields.h"


namespace bot::types {

class Voice : public BaseFile {
public:
    Voice() : BaseFile() {}
    Voice(string&);
    Voice(Value const&);
    virtual ~Voice() {}

    int duration;

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(rapidjson::Value const& value);
};

}