#include <iostream>

using namespace std;

int main(int argc, const char * argv[]){
    int T,W;
    cin >> T >> W;
    
    int dp[2][1001][32];
    int list[1001];
    
    for (int i=1;i<=T;i++){
        cin >> list[i];
    }
    
    for (int i=1;i<=T;i++){
        for (int j=1;j<=W+1;j++){
            if (list[i] == 1){
                dp[0][i][j] = max(dp[0][i-1][j]+1 , dp[1][i-1][j-1]+1);
                dp[1][i][j] = max(dp[0][i-1][j-1] , dp[1][i-1][j]  );
            }
            else {
                if (i==1 && j==1) continue;
                dp[0][i][j] = max(dp[0][i-1][j], dp[1][i-1][j-1]);
                dp[1][i][j] = max(dp[0][i-1][j-1]+1, dp[1][i-1][j]+1);
            }
        }
    }
    int result = 0;
    for (int j=1;j<=W+1;j++){
        result = max(result, dp[0][T][j]);
        result = max(result, dp[1][T][j]);
    }
    cout << result << "\n";
}
