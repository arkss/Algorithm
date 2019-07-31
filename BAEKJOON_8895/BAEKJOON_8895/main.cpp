#include <iostream>

using namespace std;

long long dp[21][21][21];

int main(int argc, const char * argv[]) {
    
    dp[1][1][1] = 1;
    for (int n=2;n<=20;n++){
        for (int l=1;l<=20;l++){
            for (int r=1;r<=20;r++){
                dp[n][l][r] = dp[n-1][l-1][r] + dp[n-1][l][r-1] + (n-2)*dp[n-1][l][r];
            }
        }
    }
    
    int T;
    cin >> T;
    for (int t=0;t<T;t++){
        int n,l,r;
        cin >> n >> l >> r;
        cout << dp[n][l][r] << endl;
    }
    return 0;
}
