#include <iostream>
#include <cmath>

using namespace std;

int solution(string s){
    int answer = 0;
    bool isFlus = true;
    for (int i=0;i<s.size();i++){
        if (s[i] == '-') isFlus = false;
        else if (s[i] == '+') continue;
        else answer = answer*10 + int(s[i] - '0');
    }
    return isFlus ? answer : answer*(-1);
}

int main(){
    cout << solution("1234") << "\n";
}