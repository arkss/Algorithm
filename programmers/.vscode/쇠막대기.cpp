#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement){
    int answer = 0;
    stack<char> s;
    char prev = ' ';
    for (int i=0;i<arrangement.size();i++){
        char now = arrangement[i];
        if (now == '('){
            s.push(now);
        } else if (prev == ')' && now == ')'){
            s.pop();
            answer += 1;
        } else if (prev == '(' && now == ')'){
            s.pop();
            answer += s.size();
        }
        prev = now;
        
        //cout << answer << "\n";
    }
    return answer;
}

int main(){
    cout << solution("()(((()())(())()))(())") << "\n";
}