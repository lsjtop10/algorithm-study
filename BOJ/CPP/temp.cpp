#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

enum Behavior { UNKNOWN, ENTER = 'E', LEAVE = 'L', CHANGE = 'C' };

Behavior behaviorFromString(string str) {
    switch (str[0]) {
    case (char)CHANGE:
        return CHANGE;
    case (char)LEAVE:
        return LEAVE;
    case (char)ENTER:
        return ENTER;
    default:
        return UNKNOWN;
    }
}

struct Command {
    Behavior behavior;
    string uid;
};

vector<string> solution(vector<string> record) {
    // UID-Name Table
    unordered_map<string, string, std::hash<string>> UIDtoDisplayNameMap = unordered_map<string, string, std::hash<string>>();
    vector<Command> commands;
    commands.reserve(record.size());\

    // parse behavior
    for (string str : record) {
        istringstream iss = istringstream(str);

        vector<string> tokens;

        string token;
        while (getline(iss, token, ' ')) {
            tokens.push_back(token);
        }

        string uid;
        string displayName;

        Behavior behavior = behaviorFromString(tokens[0]);
        uid = tokens[1];

        if (behavior != LEAVE) {
            //update display name
            displayName = tokens[2];
            auto e = UIDtoDisplayNameMap.find(uid);
            if (e != UIDtoDisplayNameMap.end()) {
                (*e).second = displayName;
            } else {
                UIDtoDisplayNameMap.insert(make_pair(uid, displayName));
            }
        }

        commands.push_back(Command{
            behavior,
            uid
        });
    }


    vector<string> answer;
    answer.reserve(record.size());

    // print
    for(int i = 0; commands.size(); i++){
        auto cmd = commands[i];

        if (cmd.behavior == CHANGE) {
            continue;
        }

        auto nameItr = UIDtoDisplayNameMap.find(cmd.uid);
        if (nameItr == UIDtoDisplayNameMap.end()) {
            continue;
        }

        string ans;
        ostringstream oss;

        oss << (*nameItr).second << "님이 ";
        switch (cmd.behavior) {
        case ENTER:
            oss << "들어왔습니다.";
            break;
        case LEAVE:
            oss << "나갔습니다.";
            break;
        }

        answer.push_back(oss.str());
    }

    return answer;
}