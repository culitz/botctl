#include "base_object.h"
#include "fields.h"


namespace bot::types {


class InlineKeyboardButton : public BaseObject {
public:
    string text;
    string url;
    std::optional<BaseObject> login_url;
    std::optional<string> callback_data;
    std::optional<string> switch_inline_query;
    std::optional<string> switch_inline_query_current_chat;
    std::optional<BaseObject> callback_game;
    std::optional<bool> pay;

    InlineKeyboardButton();
    InlineKeyboardButton(string&);
    InlineKeyboardButton(const Value&);
    virtual ~InlineKeyboardButton();
protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};


}