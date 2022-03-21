#pragma once
#include <optional>
#include "base_file.h"
#include "photo_size.h"
#include "fields.h"


namespace bot::types
{

class Animation : public BaseFile
{
public:
    int widght;
    int heght;
    int duaration;
    std::optional<PhotoSize> thumb;

    Animation() : BaseFile() {}
    Animation(string& json);
    virtual ~Animation() {}

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(rapidjson::Value const& document);
};

}