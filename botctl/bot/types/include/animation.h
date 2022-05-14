#pragma once
#include <optional>
#include "base_file.h"
#include "photo_size.h"
#include "fields.h"


namespace bot::types
{
/**
 * @brief This object represents an animation file (GIF or H.264/MPEG-4 AVC video without sound).
 */
class Animation : public BaseFile
{
public:
    /// @brief Video width as defined by sender
    int widght;
    ///  @brief Video height as defined by sende
    int heght;
    /// @brief Duration of the video in seconds as defined by sender
    int duaration;
    /// @brief Optional. Animation thumbnail as defined by sender
    std::optional<PhotoSize> thumb;

    Animation() : BaseFile() {}
    Animation(string& json);
    virtual ~Animation() {}

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(rapidjson::Value const& document);
};

}
