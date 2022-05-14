#include "dice.h"

namespace bot::types {

Dice::Dice(string& json) {
    fromString(json);
}

void Dice::fillDocument(Writer& writer) const {
    writer.Key(fields::EMOJI);
    writer.String(emoji.c_str());

    writer.Key(fields::VALUE);
    writer.Int(value);
}

void Dice::fillObject(Value const& document) {
    emoji = document[fields::EMOJI].GetString();
    value = document[fields::VALUE].GetInt();
}

}
