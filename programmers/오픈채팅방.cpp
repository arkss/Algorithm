#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record){
    vector<string> answer;
    vector<pair<string, string> > messageWithId;
    map<string, string> user;

    for (int i=0;i<record.size();i++){
        string message = record[i];
        string action = "", id="", nickname="";
        int flag = 0;
        for (int j=0;j<message.size();j++){
            if (message[j] == ' '){
                flag++;
                continue;
            }
            if (flag == 0) action += message[j];
            else if (flag == 1) id += message[j];
            else if (flag == 2) nickname += message[j];
        }
        if (action == "Enter"){
            user[id] = nickname;
            messageWithId.push_back(make_pair(id,"님이 들어왔습니다."));
        } else if (action == "Leave") {
            messageWithId.push_back(make_pair(id,"님이 나갔습니다."));
        } else if (action == "Change") {
            user[id] = nickname;
        }
    }

    for (int i=0;i<messageWithId.size();i++){
        string id = messageWithId[i].first;    
        string sub_message = messageWithId[i].second;    
        answer.push_back(user[id]+sub_message);
    }
    
    return answer;
}

int main(){
    vector<string> record;
    record.push_back("Enter uid1234 Muzi");
    record.push_back("Enter uid4567 Prodo");
    record.push_back("Leave uid1234");
    record.push_back("Enter uid1234 Prodo");
    record.push_back("Change uid4567 Ryan");
    solution(record);
}