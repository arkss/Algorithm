#include <iostream>

using namespace std;

const int INF = 987654321;

int main(int argc, const char * argv[]) {
    
    int n,k;
    cin >> n >> k;
    
    int coin[101];
    int dp[10001];
    
    for (int i=1;i<=n;i++){
        cin >> coin[i];
    }
    
    for (int i=1;i<=k;i++){
        dp[i] = INF;
    }
    
    dp[0] = 0;
    
    for (int i=1;i<=n;i++){
        for (int j=coin[i];j<=k;j++){
            dp[j] = min(dp[j], dp[j-coin[i]]+1);
        }
    }
    
    if (dp[k] == INF) dp[k] = -1;
    cout << dp[k] << "\n";
    
    
    
    return 0;
}
