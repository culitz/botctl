#include "file.h"

namespace bot::types {

File::File() : BaseFile() {

}

File::File(
    string& _file_id, 
    string& _file_unique_id, 
    std::optional<int> _file_size, 
    std::optional<string> _file_path
) :
BaseFile(),
file_path(_file_path) {
    file_id = _file_id;
    file_unique_id = _file_unique_id;
    if(_file_size)
        file_size = _file_size.value();
}

File::File(string& json) : BaseFile() {
    fromString(json);
}

File::File(const Value& value) : BaseFile() {
    fillObject(value);
}

File::~File() {}

void File::fillDocument(Writer& writer) const {
    BaseFile::fillDocument(writer);
    if(file_path) {
        writer.Key(fields::FILE_PATH);
        writer.String(file_path->c_str());
    }
}

void File::fillObject(rapidjson::Value const& document) {
    BaseFile::fillObject(document);
    if(document.HasMember(fields::FILE_PATH))
        file_path = document[fields::FILE_PATH].GetString();
}

}

