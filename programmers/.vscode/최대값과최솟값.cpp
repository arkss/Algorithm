#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    int maxNum = -987654321;
    int minNum = 987654321;
    int minusFlag = 1;
    int nowInt = 0;
    for (int i=0;i<s.size();i++){


        char now = s[i];
        if (now == '-') minusFlag = -1;
        else if (now == ' '){
            nowInt = nowInt * minusFlag;
            maxNum = max(maxNum, nowInt);
            minNum = min(minNum, nowInt);
            minusFlag = 1;
            nowInt = 0;
        } 
        else if ('0'<= now && now <= '9') {
            nowInt = nowInt * 10 + (now - '0');
        }
    }
    nowInt = nowInt * minusFlag;
    maxNum = max(maxNum, nowInt);
    minNum = min(minNum, nowInt);
    answer += to_string(minNum);
    answer += " ";
    answer += to_string(maxNum);
    return answer;
}

int main(){
    cout << solution("-1 -2 -3 -4") << "\n";
}