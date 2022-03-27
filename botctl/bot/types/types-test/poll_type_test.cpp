#include <vector>
#include <sstream>
#include "gtest/gtest.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "../poll.h"
#include "../message_entity.h"
#include "../poll_options.h"
#include "../user.h"
#include "../fields.h"

namespace test_type_poll {

using namespace bot::types;

TEST(test_type_poll, fromString) {
    std::string id = "100";
    std::string question = "q";
    std::vector<PollOption> options {
        PollOption("text1", 1),
        PollOption("text2", 2)
    };

    int total_voter_count = 2;
    bool is_closed = true;
    bool is_anonymous = false;
    std::string type = "type";
    bool allows_multiple_answers = true;
    int correct_option_id = 55;
    string explanation = "1234567";

    string username = "username";
    bool is_bot = true;
    string exp_text = "foo";
    std::vector<MessageEntity> explanation_entities {
        MessageEntity(exp_text, 1, 2),
        MessageEntity(exp_text, 4, 5, "url", User(username, is_bot), "en")
    };

    int open_period = 123;
    int close_date = 1234567890;

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

    writer.StartObject();
    writer.Key(fields::ID);
    writer.String(id.c_str());

    writer.Key(fields::QUESTION);
    writer.String(question.c_str());

    writer.Key(fields::OPTIONS);
    writer.StartArray();
    for(PollOption& opt : options) {
        opt.asNestedObject(writer);
    }
    writer.EndArray();

    writer.Key(fields::TOTAL_VOITER_COUNT);
    writer.Int(total_voter_count);

    writer.Key(fields::IS_CLOSED);
    writer.Bool(is_closed);

    writer.Key(fields::IS_ANONYMOUS);
    writer.Bool(is_anonymous);

    writer.Key(fields::TYPE);
    writer.String(type.c_str());

    writer.Key(fields::ALLOW_MULTIPLE_ANSWERS);
    writer.Bool(allows_multiple_answers);

    writer.Key(fields::CORRECT_OPTION_ID);
    writer.Int(correct_option_id);

    writer.Key(fields::EXPLANATION);
    writer.String(explanation.c_str());


    writer.Key(fields::EXPLANATION_ENTITIES);
    writer.StartArray();
    for(MessageEntity& msg: explanation_entities) {
        msg.asNestedObject(writer);
    }
    writer.EndArray();

    writer.Key(fields::OPEN_PERIOD);
    writer.Int(open_period);

    writer.Key(fields::CLOSE_DATE);
    writer.Int(close_date);
    writer.EndObject();

    string json = buffer.GetString();
    Poll poll(json);

    ASSERT_EQ(poll.id, id);
    ASSERT_EQ(poll.question, question);
    ASSERT_EQ(poll.total_voter_count, total_voter_count);
    ASSERT_EQ(poll.is_closed, is_closed);
    ASSERT_EQ(poll.is_anonymous, is_anonymous);
    ASSERT_EQ(poll.type, type);
    ASSERT_EQ(poll.allows_multiple_answers, allows_multiple_answers);
    ASSERT_EQ(poll.correct_option_id, correct_option_id);
    ASSERT_EQ(poll.explanation, explanation);
    ASSERT_EQ(poll.open_period, open_period);
    ASSERT_EQ(poll.close_date, close_date);
    
    for(size_t i = 0; i < poll.options.size(); i++) {
        ASSERT_EQ(poll.options[i].text, options[i].text);
        ASSERT_EQ(poll.options[i].voter_count, options[i].voter_count);
    }

    /// \todo need to add checking optional values
    for(size_t i = 0; i < poll.explanation_entities->size(); i++) {
        ASSERT_EQ((*poll.explanation_entities)[i].type, explanation_entities[i].type);
        ASSERT_EQ((*poll.explanation_entities)[i].offset, explanation_entities[i].offset);
        ASSERT_EQ((*poll.explanation_entities)[i].length, explanation_entities[i].length);
    }
}

}