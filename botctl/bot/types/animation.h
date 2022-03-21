#pragma once
#include <optional>
#include "base_file.h"
#include "photo_size.h"


namespace bot::types
{

class Animation : public BaseFile
{
public:
    inline static const string WIDTH = "width";
    inline static const string HEIGHT = "height";
    inline static const string DUARATION = "duration";
    inline static const string THUMB = "thumb";


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