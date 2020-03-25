#include <iostream>
#include <stack>

using namespace std;

bool solution(string str){
    stack<char> s;
    for (int i=0;i<str.size();i++){
        char now = str[i];
        if (now == '('){
            s.push(now);
        } else if (now == ')'){
            if (s.empty()){
                return false;    
            } else {
                s.pop();
            }  
        } 
    }
    if (!s.empty()) return false;
    else return true;
}

int main(){
    cout <<solution("()()") << "\n";
    return 0;
}