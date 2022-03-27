#pragma once
#include "base_file.h"


namespace bot::types {

class PhotoSize : public BaseFile
{
public:
    inline static const string WIDTH = "width";
    inline static const string HEIGHT = "height";

    int width;
    int height;

    PhotoSize() : BaseFile() {}
    PhotoSize(string&);
    PhotoSize(Value const&);
    virtual ~PhotoSize() {}

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(rapidjson::Value const& document);
    
private:
    typedef BaseFile Parent;
};

}

