#include <iostream>
#include <vector>

using namespace std;

bool solution(string s){
    if (s.length() != 4 && s.length() != 6){
        return false;
    }
    for (char item : s){
        if (item < '0' || item > '9')
            return false;
    }
    return true;
}

int main(){
    cout << solution("1234") << "\n";
    return 0;
}