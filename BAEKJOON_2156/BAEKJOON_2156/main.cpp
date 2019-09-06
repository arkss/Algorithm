#include <iostream>

using namespace std;

int max(int a,int b,int c){
    return max(max(a,b), c);
}

int main(){
    int n;
    cin >> n;
    int cup[10001];
    int dp[10001];
    
    for (int i=1;i<=n;i++){
        cin >> cup[i];
    }
    dp[0] = 0;
    dp[1] = cup[1];
    dp[2] = dp[1] + cup[2];
    for (int i=3;i<=n;i++){
        dp[i] = max(dp[i-3]+cup[i]+cup[i-1], dp[i-2]+cup[i], dp[i-1]);
    }
    
    cout << dp[n] << "\n";
    
    return 0;
}
