#pragma once
#include "base_object.h"
#include "fields.h"


namespace bot::types {

class WebAppInfo : public BaseObject {
public:
    WebAppInfo();
    WebAppInfo(string& json);
    WebAppInfo(Value const&);
    virtual ~WebAppInfo() {}

    string url;
protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};

}