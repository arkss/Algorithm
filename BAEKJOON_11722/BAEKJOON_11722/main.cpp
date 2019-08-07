#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    int list[1001];
    int dp[1001];
    
    for (int i=1;i<=N;i++){
        cin >> list[i];
    }
    
    int maxLength = 0;
    
    
    for (int i=1;i<=N;i++){
        dp[i] = 1;
        for (int j=1;j<=i;j++){
            if (list[j] > list[i])
                dp[i] = max(dp[j]+1,dp[i]);
        }
        
        maxLength = max(maxLength, dp[i]);
    }
    
//    for (int i=0;i<N;i++){
//        cout << dp[i] << " " ;
//    }
//    cout << "\n";
//
    cout << maxLength << "\n";
    
    return 0;
}
