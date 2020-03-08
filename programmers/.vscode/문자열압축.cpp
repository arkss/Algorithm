#include <iostream>
#include <string>

using namespace std;

int solution(string s){
    int answer = 0;
    int min_length = 987654321;
    
    for (int i=1;i<=s.size()/2+1;i++){
        string prev = s.substr(0,i);
        int cnt = 1;
        string change_s = prev;
        for (int j=i;j<s.size();j+=i){
            string now = s.substr(j,i);
            if (prev == now){
                cnt++;
            } else if (cnt == 1){
                change_s += now;
            }
            else {
                change_s += to_string(cnt);
                change_s += now;
                cnt = 1;
            }
            prev = now;
        }
        if (cnt != 1){
            change_s += to_string(cnt);
        }

        if (min_length>change_s.size()){
            min_length = change_s.size();
        }
    }
    return min_length;
}

int main(){

    cout << solution("a") << "\n";
    return 0;
}
