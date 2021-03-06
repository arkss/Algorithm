#include <iostream>
#include <vector>

using namespace std;

int dp[103][103];

int solution(int m,int n, vector<vector<int>> puddles){
    for (int i=0;i<puddles.size();i++){
        int x = puddles[i][1];
        int y = puddles[i][0];
        dp[x][y] = -1;
    }
    dp[1][0] = 1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (dp[i][j] == -1) continue;
            if (dp[i-1][j] == -1 || dp[i][j-1] == -1)
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]+1) % 1000000007;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1] )% 1000000007;
        }
    }

    return dp[n][m] % 1000000007;
}

int main(){
    cout << solution(4,3, {{2,2}}) << "\n";
    return 0;
}