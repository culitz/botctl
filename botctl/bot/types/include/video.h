#pragma once
#include "base_file.h"
#include "photo_size.h"

namespace bot::types
{

class Video : public BaseFile {
public:
    Video() : BaseFile() {}
    Video(string& json);
    Video(Value const&);
    virtual ~Video() {}

    /// Video width as defined by sender
    int width;

    /// Video height as defined by sender
    int height;

    /// Duration of the video in seconds as defined by sender
    int duration;
    
    /// Video thumbnail
    std::optional<PhotoSize> thumb;

 protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(rapidjson::Value const& document);   
};

} // namespace bot::types
