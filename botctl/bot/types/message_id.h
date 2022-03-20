#pragma once
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include "base_object.h"



namespace bot::types
{

class MessageId : public BaseObject
{
public:
    inline static const string MESSAGE_ID = "message_id";

    MessageId(string& json);
    virtual ~MessageId();

    int message_id;
protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(rapidjson::Document& document);
};


}
