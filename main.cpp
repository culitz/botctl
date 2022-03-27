#include <sstream>
#include <iostream>
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "botctl/bot/types/message_entity.h"
#include "botctl/bot/types/video.h"
#include "botctl/bot/types/fields.h"
#include "botctl/bot/types/poll_options.h"
#include "botctl/bot/types/user.h"
#include "botctl/bot/types/poll.h"


using namespace bot::types;


int main()
{
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

    std::vector<MessageEntity> explanation_entities {
        MessageEntity("foo", 1, 2),
        MessageEntity("bar", 4, 5, "url", User("user", true), "en")
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
    std::cout << json << std::endl;
    bot::types::Poll poll(json);
}
