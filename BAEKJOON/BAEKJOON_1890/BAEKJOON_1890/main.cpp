#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int board[101][101];
    long long dp[101][101] = {0,};
    int N;
    cin >> N;
    
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> board[i][j];
        }
    }
    
    dp[0][0] = 1;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (i==N-1 && j==N-1) continue;
            if (!dp[i][j]) continue;
            int jumpCount = board[i][j];
            if (i+jumpCount < N)
                dp[i+jumpCount][j]+= dp[i][j];
            if (j+jumpCount < N)
                dp[i][j+jumpCount]+= dp[i][j];
            
        }
    }

    cout << dp[N-1][N-1] << "\n";
    
    return 0;
}
