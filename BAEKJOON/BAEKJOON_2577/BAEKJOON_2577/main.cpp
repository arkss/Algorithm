#include <iostream>
#include <string>
#include <string.h>


using namespace std;

int main(int argc, const char * argv[]) {
    // 각 수가 몇 번 나왔는지 담을 배열
    int arr[10] = {0};
    int A,B,C;
    int x;
    int length;
    int i;
    string str;
    
    cin >> A >> B >> C;
    
    x = A * B * C;
    
    
    str = to_string(x); // 정수를 문자열로 바꾸는 함수
    length = str.length();// 문자열의 길이
    
    for(i=0;i<length;i++){
        // string의 아스키 코드를 생각하면 index와 일치하지 않으므로 '0' 을 빼서 맞춰준다.
        arr[str[i]-'0']++;
    }
    for (i=0;i<10;i++){
        cout << arr[i] << endl;
    }
    
}

