#pragma once
#include "base_file.h"
#include "fields.h"


namespace bot::types
{

class Dice : public BaseFile {
public:
    string emoji;
    int value;

    Dice() : BaseFile() {}
    Dice(string&);
    ~Dice() {}

protected:
    virtual void fillDocument(Writer& writer) const override;
    virtual void fillObject(Value const& document) override;
};

}
