#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPel(string s){
    for (int i=0;i<s.size()/2;i++){
        if (s[i] != s[s.size()-1-i]) return false;
    }
    return true;
}

int solution(string s){
    int answer = 0;
    for (int i=0;i<s.size();i++){
        for (int j=1;i+j<=s.size();j++){
            if (s[i] != s[i+j-1]) continue;
            string temp = s.substr(i,j);
            if (temp.size() > answer && isPel(temp)) {
                answer = temp.size();
            }
        }
    }
    return answer;
}

int main(){
    cout << solution("abcdcba") << "\n";
    return 0;
}