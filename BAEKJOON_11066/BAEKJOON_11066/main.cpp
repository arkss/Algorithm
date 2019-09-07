#include <iostream>
#include <cstring>

using namespace std;

int file[501];
int sum[501];
int dp[501][501];

int go (int i,int j){
    if (i==j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    
    for (int k=i;k<j;k++){
        int temp = go(i,k) + go(k+1,j) + sum[j] - sum[i-1];
        if (dp[i][j] == -1 || dp[i][j] > temp)
            dp[i][j] = temp;
    }
    return dp[i][j];
}

int main(){
    int T;
    cin >> T;
    for (int t=0;t<T;t++){
        memset(dp,-1,sizeof(dp));
        memset(sum,0,sizeof(sum));
        
        int N;
        cin >> N;
        
        for (int i=1;i<=N;i++){
            cin >> file[i];
            sum[i] = sum[i-1] + file[i];
        }
        
        cout << go(1,N) <<"\n";
    }
    return 0;
}
