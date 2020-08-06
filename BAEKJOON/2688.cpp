#include <iostream>

using namespace std;

long long dp[65][10];

void create_dp_table()
{
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1ll;

    for (int i = 1; i <= 64; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k <= j; k++)
                dp[i][j] += dp[i - 1][k];
}

int main()
{

    create_dp_table();

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;

        long long answer = 0;
        for (int j = 0; j < 10; j++)
            answer += dp[n][j];

        cout << answer << "\n";
    }
}