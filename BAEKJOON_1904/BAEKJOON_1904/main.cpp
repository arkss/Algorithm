#include <iostream>

using namespace std;

long long dp[1000001];

int main(int argc, const char * argv[]) {
    int N;
    int i;
    
    cin >> N;
    
    dp[1] = 1;
    dp[2] = 2;
    
    for(i=3;i<=N;i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }
    
    cout << dp[N];
}
