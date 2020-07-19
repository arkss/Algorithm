#include <iostream>

using namespace std;

long long dp[101];

int main()
{
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = dp[3] + dp[1]; // 2
    dp[5] = 2;
    dp[6] = dp[5] + dp[3]; // 3
    dp[7] = dp[6] + dp[2]; // 4
    dp[8] = dp[7] + dp[1]; // 5
    for (int i = 9; i < 101; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int temp;
        cin >> temp;
        cout << dp[temp] << "\n";
    }
}
