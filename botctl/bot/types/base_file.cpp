#include "base_file.h"


namespace bot::types
{

BaseFile::BaseFile(string json)
{
    fromString(json);
}

void BaseFile::fillDocument(Writer &writer) const
{
    writer.Key(FILE_ID.c_str());
    writer.String(file_id.c_str());

    writer.Key(FILE_UNIQUE_ID.c_str());
    writer.String(file_unique_id.c_str());

    writer.Key(FILE_SIZE.c_str());
    writer.Int(file_size);
}

void BaseFile::fillObject(rapidjson::Document &document)
{
    file_id = document[FILE_ID.c_str()].GetString();
    file_unique_id = document[FILE_UNIQUE_ID.c_str()].GetString();
    file_size = document[FILE_SIZE.c_str()].GetInt();

    if(document.HasMember(FILE_NAME.c_str()))
        file_name = document[FILE_NAME.c_str()].GetString();
    
    if(document.HasMember(MIME_TYPE.c_str()))
        mime_type.emplace(document[MIME_TYPE.c_str()].GetString());
    
}


}
