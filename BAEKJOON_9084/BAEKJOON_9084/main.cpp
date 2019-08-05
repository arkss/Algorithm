#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    for (int t=0;t<T;t++){
        int N;
        cin >> N;
        int coin[21];
        for (int i=1;i<=N;i++){
            cin >> coin[i];
        }
        int amount;
        cin >> amount;
        
        int dp[10001] = {0};
        
        dp[0] = 1;
        for (int i=1;i<=N;i++){
            for (int j=coin[i];j<=amount;j++){
                dp[j] += dp[j-coin[i]];
            }
        }
        
        cout << dp[amount] << "\n";
        
        
        
        
        
        
    }
    return 0;
}
