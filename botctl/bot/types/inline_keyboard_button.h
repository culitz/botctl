#include "base_object.h"
#include "login_url.h"
#include "fields.h"
#include "login_url.h"

namespace bot::types {

/// @todo Write a unittests
class InlineKeyboardButton : public BaseObject {
public:
    string text;
    string url;
    std::optional<LoginUrl> login_url;
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
