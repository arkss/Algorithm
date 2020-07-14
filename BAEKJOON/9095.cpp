#include <iostream>

using namespace std;

int dp[11];

void init_dp()
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= 11; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
}

int main()
{
    int T;
    cin >> T;

    init_dp();

    for (int i = 0; i < T; i++)
    {
        int num;
        cin >> num;
        cout << dp[num] << "\n";
    }
}