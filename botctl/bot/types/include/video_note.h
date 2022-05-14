#pragma once
#include "base_file.h"
#include "photo_size.h"
#include "fields.h"


namespace bot::types {

class VideoNote : public BaseFile {

public:
    VideoNote() : BaseFile() {}
    VideoNote(string&);
    VideoNote(Value const&);

    /// Video width and height (diameter of the video message) as defined by sender
    int length;
    /// Duration of the video in seconds as defined by sender
    int duration;
    /// Video thumbnail
    std::optional<PhotoSize> thumb;

private:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(rapidjson::Value const& value);
};

}
