#include <iostream>
#include <cstring>

using namespace std;

int matrix[500][2];
int dp[501][501];

int go(int i,int j){
    if (dp[i][j] != -1) return dp[i][j];
    if (i==j) return 0;
    if (i+1 == j){
        return matrix[i][0]*matrix[i][1]*matrix[j][1];
    }
    
    for (int k=i;k<j;k++){
        int temp = go(i,k) + go(k+1,j);
        int matrixMul = matrix[i][0]*matrix[k][1]*matrix[j][1];
        
        if (dp[i][j] == -1 || dp[i][j] > temp+matrixMul)
            dp[i][j] = temp+matrixMul;
    }
    return dp[i][j];
}

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    memset(dp,-1,sizeof(dp));
    
    for (int i=0;i<N;i++){
        cin >> matrix[i][0];
        cin >> matrix[i][1];
    }
    
    cout << go(0,N-1) << "\n";
    return 0;
}
