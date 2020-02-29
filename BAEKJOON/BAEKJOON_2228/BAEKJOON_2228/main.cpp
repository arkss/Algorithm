#include <iostream>

using namespace std;

int N,M;
int dp[101][51];
int visited[101][51];
int list[101];
int sum[101];

const int minValue = -987654321;


int go(int i,int j){
    // 구간이 없을 때
    if (j == 0) return 0;
    // 구간을 다 못썼는데 더 이상 사용할 리스트가 없을 때
    if (i <= 0) return minValue;
    
    if (visited[i][j]) return dp[i][j];
    visited[i][j] = 1;
    
    dp[i][j] = go(i-1,j);
    
    for (int k=1;k<=i;k++){
        int temp = go(k-2,j-1) + sum[i] - sum[k-1];
        dp[i][j] = max(dp[i][j], temp);
    }
    return dp[i][j];
}

int main(int argc, const char * argv[]) {
    
    
    
    cin >> N >> M;
    
    for (int i=1;i<=N;i++){
        cin >> list[i];
        sum[i] = list[i] + sum[i-1];
    }
    
    cout <<  go(N,M) << "\n";
    
    return 0;
}
