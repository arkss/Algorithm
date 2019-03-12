/*
 dp문제이다.
 먼저 N이 짝수냐 홀수냐에 따라 구하는 방법이 다르다.
 홀수일 경우 홀수*3은 홀수이므로 총 홀수 개의 칸이 존재하고 한 블럭은짝수개이기 때문에 다 채울 수 없다.
 짝수개일 경우를 고려해보자.
 
 
 */


#include <iostream>

using namespace std;

int dp[31];

int main(int argc, const char * argv[]) {
    int N;
    
    cin >> N;
    dp[0] = 1;
    dp[2] = 3;
    for(int i=3;i<=N;i++){
        if(i%2==0){
// i개의 타일(i*3인데 편의 상 3은 생략하자.)을 채우기 위해서는 i-2개와 2개 타일 채워주는 경우를 곱해준다.
            dp[i] = dp[i-2] *dp[2];
            // 이렇게 타일을 채울 경우, 애매하게 걸치는 블럭을 다워줄 수 없다. 애매하게 걸치는 경우들을 계산해준다. 각 상황에 대해 위아래 대칭하여 경우는 2개 나온다.
            for(int j=0;j<=i-4;j++)
                dp[i] += dp[j]*2;

        }
        else
            dp[i] = 0;
    }
//    for(int i=0;i<=N;i++){
//        cout.width(3);
//        cout << dp[i];
//    }
    cout << dp[N];
}
