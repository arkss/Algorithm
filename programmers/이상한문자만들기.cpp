#include <iostream>
#include <string>

using namespace std;

string solution(string s){
    int isChanged = true;
    for (int i=0;i<s.size();i++){
        if (s[i] == ' ') {
            isChanged = true;
            continue;
        }
        if (isChanged && 'a' <= s[i] && s[i] <= 'z') s[i] -= 32;
        else if (!isChanged && 'A' <= s[i] && s[i] <= 'Z') s[i] += 32;
        isChanged = !isChanged;
    }
    return s;
}

int main(){
    cout << solution("try hello world test") << "\n";
    return 0;
}