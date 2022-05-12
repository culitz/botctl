#include "web_app_info.h"

namespace bot::types {

WebAppInfo::WebAppInfo() : BaseObject() {}

WebAppInfo::WebAppInfo(string& json) : BaseObject() {
    fromString(json);
}

WebAppInfo::WebAppInfo(Value const& value) : BaseObject() {
    fillObject(value);
}

void WebAppInfo::fillDocument(Writer& writer) const {
    writer.Key(fields::URL);
    writer.String(url.c_str());
}

void WebAppInfo::fillObject(Value const& document) {
    url = document[fields::URL].GetString();
}
    
}