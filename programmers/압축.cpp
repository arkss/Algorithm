#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;

    for (char temp='A';temp<='Z';temp++){
        string tempStr = "";
        tempStr += temp;
        m[tempStr] = temp-'A'+1;
    }

    if (msg.size() == 1) 
        answer.push_back(m[msg]);
        return answer;
    }

    int lastIndex = 27;
    string prev = "";
    prev += msg[0];

    int j;
    
    for (int i=0;i<msg.size();i+=j-1){
        for (j=1;j<msg.size();j++){
            if (i+j > msg.size()) break;
            string key = msg.substr(i,j);
            if (m.find(key) == m.end()){
                m[key] = lastIndex++;
                break;
            }
            prev = key;
        }
        answer.push_back(m[prev]);
    }

    return answer;
}

int main(){

    string testStr = "A";
    
    solution(testStr);

}