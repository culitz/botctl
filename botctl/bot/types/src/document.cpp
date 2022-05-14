#include "document.h"


namespace bot::types 
{

Document::Document(string& json) : BaseFile(json) {}


void Document::fillDocument(Writer& writer) const
{
    BaseFile::fillDocument(writer);
    if(thumb)
    {
        writer.Key(THUMB.c_str());
        thumb->asNestedObject(writer);
    }
}

void Document::fillObject(rapidjson::Value const& document)
{
    BaseFile::fillObject(document);
    if(document.HasMember(THUMB.c_str()))
    {
        PhotoSize photo_size;
        photo_size.fromNestedObject(document);
        thumb.emplace(photo_size);
    }
}

}
