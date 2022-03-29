#pragma once
#include "base_file.h"
#include "fields.h"

namespace bot::types {

class File : public BaseFile {
public:
    std::optional<string> file_path;
    File();
    File(string&);
    File(const Value&);
    File(
        string& file_id, 
        string& file_unique_id, 
        std::optional<int> file_size, 
        std::optional<string> file_path
    );
    virtual ~File();

private:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(rapidjson::Value const& document);
};

}