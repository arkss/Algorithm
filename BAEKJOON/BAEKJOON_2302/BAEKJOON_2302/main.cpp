#include <iostream>

using namespace std;

int dp[45];


void fibo(int start, int end)
{
    int i;
    int count = 1;
    for(i=start;i<end;i++){
        if (count == 1 || count == 2){
            dp[i] = count;
            count++;
        }
        else
            dp[i] = dp[i-1] + dp[i-2];
    }
}

int main(int argc, const char * argv[]) {
    int N,M;
    int i;
    int answer = 1; // 정답
    
    cin >> N;
    
    cin >> M;
    
    int temp = 0;
    int pre=1;
    dp[0] = 1;
    for (i=0;i<M;i++){
        cin >> temp;
        fibo(pre,temp);
//        cout << i << ":"<<dp[temp-1];
        if (dp[temp-1] != 0)
            answer *= dp[temp-1];
        
        pre = temp+1;
    }
    if (temp != N){
        fibo(pre,N+1);
        answer *= dp[N];
    }
    
    
//    for(i=0;i<=N;i++){
//        cout.width(2);
//        cout << dp[i];
//    }
    cout << answer;
}
