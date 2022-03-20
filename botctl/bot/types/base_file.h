#pragma once
#include "base_object.h"


namespace bot::types
{

class BaseFile: public BaseObject
{
public:
    inline static const string FILE_ID = "file_id";
    inline static const string FILE_UNIQUE_ID = "file_unique_id";
    inline static const string FILE_SIZE = "file_size";
    inline static const string FILE_NAME = "file_name";
    inline static const string MIME_TYPE = "mime_type";

    string file_id;
    string file_unique_id;
    int file_size;
    std::optional<string> file_name;
    std::optional<string> mime_type;

    BaseFile(string json);
    BaseFile() {}
    virtual ~BaseFile() {}

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(rapidjson::Document& document);
};

}
