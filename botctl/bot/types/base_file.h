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

    string file_id;
    string file_unique_id;
    int file_size;

    BaseFile(string json);
    BaseFile() {}
    virtual ~BaseFile() {}

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Document& document);

};

}
