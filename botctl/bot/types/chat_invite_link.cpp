#include "chat_invite_link.h"

namespace bot::types {

ChatInviteLink::ChatInviteLink() : BaseObject() {

}

ChatInviteLink::ChatInviteLink(std::string& json) : BaseObject() {
    fromString(json);
}

ChatInviteLink::ChatInviteLink(Value const& value) {
    fromNestedObject(value);
}

ChatInviteLink::ChatInviteLink(
    std::string invite_link,
    User creator,
    bool creates_join_request,
    bool is_primary,
    bool is_revoked,
    std::optional<std::string> name,
    std::optional<int> expire_date,
    std::optional<int> member_limit,
    std::optional<int> pending_join_request_count
) : BaseObject(),
    invite_link(invite_link),
    creator(creator),
    creates_join_request(creates_join_request),
    is_primary(is_primary),
    is_revoked(is_revoked),
    name(name),
    expire_date(expire_date),
    member_limit(member_limit),
    pending_join_request_count(pending_join_request_count)
{}

void ChatInviteLink::fillDocument(Writer& writer) const {
    writer.Key(fields::INVITE_LINK);
    writer.String(invite_link.c_str());

    writer.Key(fields::CREATOR);
    creator.asNestedObject(writer);

    writer.Key(fields::CREATES_JOIN_REQUEST);
    writer.Bool(creates_join_request);

    writer.Key(fields::IS_PRIMARY);
    writer.Bool(is_primary);

    writer.Key(fields::IS_REVOKED);
    writer.Bool(is_revoked);

    if(name) {
        writer.Key(fields::NAME);
        writer.String(name->c_str());
    }

    if(expire_date) {
        writer.Key(fields::EXPIRE_DATE);
        writer.Int(*expire_date);
    }

    if(member_limit) {
        writer.Key(fields::MEMBER_LIMIT);
        writer.Int(*member_limit);
    }

    if(pending_join_request_count) {
        writer.Key(fields::PENDING_JOIN_REQUEST_CONST);
        writer.Int(*pending_join_request_count);
    }
}

void ChatInviteLink::fillObject(Value const& document) {
    invite_link = document[fields::INVITE_LINK].GetString();
    creator.fromNestedObject(document[fields::CREATOR]);
    creates_join_request = document[fields::CREATES_JOIN_REQUEST].GetBool();
    is_primary = document[fields::IS_PRIMARY].GetBool();
    is_revoked = document[fields::IS_REVOKED].GetBool();
    name = getOptString(document, fields::NAME);
    expire_date = getOptInt(document, fields::EXPIRE_DATE);
    member_limit = getOptInt(document, fields::MEMBER_LIMIT);
    pending_join_request_count = getOptInt(document, fields::PENDING_JOIN_REQUEST_CONST);
}	

}