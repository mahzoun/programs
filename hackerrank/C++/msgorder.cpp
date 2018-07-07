#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message {
public: 
    int index;
    string msg;
    Message() 
    {
        msg = "";
        index = 0;
    }

    Message(string str)
    {
        msg = str;
        index = 0;
    }

    Message(string str, int cnt)
    {
        msg = str;
        index = cnt;
    }
    const string& get_text() {
        return msg;    
    }
    bool operator < (Message const &msg2){
        return index < msg2.index;
    }
};

class MessageFactory {
public:
    int counter = 0;
    MessageFactory() {}
    Message create_message(const string& text) {
        cerr << counter <<endl;
        Message msg(text, counter);
        MessageFactory::counter++;
        return msg;
    }
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}

