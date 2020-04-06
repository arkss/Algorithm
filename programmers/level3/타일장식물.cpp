#include <iostream>
#include <vector>

using namespace std;

long long dp[81];

long long solution(int N){
    dp[1] = 4;
    dp[2] = 6;
    for (int i=3;i<=N;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    long long answer = dp[N];
    return answer;
}

int main(){
    cout << solution(5) << "\n";
    return 0;
}