#pragma once
#include "base_file.h"
#include "photo_size.h"


namespace bot::types 
{

class Document : public BaseFile
{
public:
    inline static const string THUMB = "thumb";
    std::optional<PhotoSize> thumb;

    Document(string&);
    Document() : BaseFile() {}
    virtual ~Document() {}
private:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(rapidjson::Value const& document);
};

}