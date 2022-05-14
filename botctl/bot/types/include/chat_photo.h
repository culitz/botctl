#pragma once
#include "base_object.h"
#include "fields.h"

namespace bot::types {

class ChatPhoto : public BaseObject {
public:
    ChatPhoto();
    ChatPhoto(std::string& json);
    ChatPhoto(Value const& document);
    ChatPhoto(
        std::string small_file_id,
        std::string small_file_unique_id,
        std::string big_file_id,
        std::string big_file_unique_id
    );

    virtual ~ChatPhoto();

    std::string small_file_id;
    std::string small_file_unique_id;
    std::string big_file_id;
    std::string big_file_unique_id;

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};

}