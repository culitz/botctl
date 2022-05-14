#pragma once
#include "base_file.h"


namespace bot::types
{

class Audio : public BaseFile
{
public:
    // @todo Move to BaseFile
    inline static const string DURATION = "duration";
    inline static const string PERFORMER = "performer";
    inline static const string TITLE = "title";

    int duration;
    std::optional<string> performer;
    std::optional<string> title;

    Audio(std::string& json);
    Audio() {}
    virtual ~Audio() {}

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(rapidjson::Value const& document);
};

} // namespace bot::types
