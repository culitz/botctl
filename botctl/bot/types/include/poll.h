#include <vector>
#include "base_object.h"
#include "poll_options.h"
#include "message_entity.h"
#include "fields.h"

namespace bot::types {

class Poll : public BaseObject {
public:
    /// Unique poll identifier
    string id;
    /// Poll question, 1-300 characters
    string question;
    /// PollOption	List of poll options
    std::vector<PollOption> options;
    /// Total number of users that voted in the poll
    int total_voter_count;
    /// True, if the poll is closed
    bool is_closed;
    /// True, if the poll is anonymous
    bool is_anonymous;
    /// Poll type, currently can be “regular” or “quiz”
    string type;
    /// True, if the poll allows multiple answers
    bool allows_multiple_answers;
    /// 0-based identifier of the correct answer option. Available only 
    /// for polls in the quiz mode, which are closed, or was sent (not forwarded) 
    /// by the bot or to the private chat with the bot.
    std::optional<int> correct_option_id;
    /// Text that is shown when a user chooses an incorrect answer or taps 
    /// on the lamp icon in a quiz-style poll, 0-200 characters
    std::optional<string> explanation;
    /// Special entities like usernames, URLs, bot commands, etc. that appear in the explanation
    std::optional<std::vector<MessageEntity>> explanation_entities;
    /// Amount of time in seconds the poll will be active after creation
    std::optional<int> open_period;
    /// Point in time (Unix timestamp) when the poll will be automatically closed
    std::optional<int> close_date;

    Poll();
    Poll(string&);
    Poll(const Value&);
    virtual ~Poll();

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
}; 

}