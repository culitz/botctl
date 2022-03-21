#include "audio.h"

namespace bot::types
{

Audio::Audio(std::string& json)
{
    fromString(json);
}

void Audio::fillDocument(Writer& writer) const
{
    
}

void Audio::fillObject(rapidjson::Value const& document)
{
    duration = document[DURATION.c_str()].GetInt();
    if(document.HasMember(PERFORMER.c_str()))
        performer = document[PERFORMER.c_str()].GetString();

    if(document.HasMember(TITLE.c_str()))
        title = document[TITLE.c_str()].GetString();
}

}