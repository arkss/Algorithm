#include <iostream>
#include <queue>

using namespace std;

bool solution(string s){
    queue<char> q;
    for (int i=0;i<s.size();i++){
        char now = s[i];
        if (now == '('){
            q.push(now);
        } else if (now == ')'){
            if (q.empty()){
                return false;    
            } else {
                q.pop();
            }  
        } 
    }
    if (!q.empty()) return false;
    else return true;
}

int main(){
    cout <<solution("()()") << "\n";
    return 0;
}