#include "base_object.h"
#include "chat.h"
#include "user.h"
#include "chat_invite_link.h"

namespace bot::types {

class ChatJoinRequest : public BaseObject {
public:
    Chat                            chat;
    User                            from;
    int                             date;
    std::optional<string>           bio;
    std::optional<ChatInviteLink>   invite_link;

    ChatJoinRequest();
    ChatJoinRequest(string& json);
    ChatJoinRequest(Value const& document);
    ChatJoinRequest(
        Chat chat,
        User from,
        int date,
        std::optional<string> bio,
        std::optional<ChatInviteLink> invite_link
    );

    virtual ~ChatJoinRequest() {}   
protected:
    virtual void fillDocument(Writer& writer) const override;
    virtual void fillObject(Value const& document) override;
};

}