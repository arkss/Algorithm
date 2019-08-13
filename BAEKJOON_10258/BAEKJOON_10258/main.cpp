#include <iostream>

using namespace std;

int main(){
    
    
    int T;
    cin >> T;
    
    for (int t=0;t<T;t++){
        string s;
        cin >> s;
        
        // digit 는 초기값 '0'
        char digit = '0';
        long long ans = 0;
        // 배열 길이 만큼 반복
        for (int i=0; i<s.size(); i++) {
            
            // s[i] 가 1이면 0으로 바꿔주기 위해 횟수가 증가한다.
            if (s[i] != digit) {
                ans += 1LL << (s.size()-i-1);
            }
            
            // 바뀌주기 위해서는 바로 뒤에 값이
            // digit 는 s[i] 와 다르면 1 같으면 0
            digit = '0' + (digit != s[i]);
            
        }
        cout << ans << '\n';
    }
    
    return 0;
}


/*
 
 문제를 다르게 접근
 00..00 에서 주어진 문자열로 바꾸는 문제
 
 오른쪽에서 i번째 비트를 0->1 로 하기 위해서는 2^(i-1)
 
 */
