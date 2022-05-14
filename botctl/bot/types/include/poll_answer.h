#pragma once

#include <vector>
#include "base_object.h"
#include "user.h"
#include "fields.h"


namespace bot::types {

class PollAnswer : public BaseObject {
public:
    string poll_id;
    User user;
    std::vector<int> option_ids;
    PollAnswer();
    PollAnswer(string&);
    PollAnswer(Value const&);
    virtual ~PollAnswer();
protected:
    virtual 
    void fillDocument(Writer& writer) const 
    override;

    virtual 
    void fillObject(rapidjson::Value const& document) 
    override;
};

}