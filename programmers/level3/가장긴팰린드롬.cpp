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
    int answer = 1;
    int len = s.size();
    if (len == 0) return 0;

    while (len >=2){
        int start = 0;
        for (int i=0;i<=s.size()-len;i++){
            bool flag = false;

            if (len % 2 != 0){
                for (int j=0;j<len/2;j++){
                    if (s[i+j] != s[i+len/2*2-j]){
                        flag = true;
                        break;
                    }
                }
            }
            else {
                for (int j=0;j<len/2;j++){
                    if (s[i+j] != s[i+len-1-j]){
                        flag = true;
                        break;
                    }
                }
            }

            if (!flag) return len;
        }
        len -= 1;
    }
    return answer;
}

int main(){
    cout << solution("abcdcba") << "\n";
    return 0;
}