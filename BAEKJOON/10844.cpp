#include <iostream>

using namespace std;

// dp[i][j] : j번째 자리 수 중 i로 끝나는 개수
long long dp[10][101];

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i < 10; i++)
    {
        dp[i][1] = 1LL;
    }

    for (int j = 2; j <= N; j++)
    {
        dp[0][j] = dp[1][j - 1];
        for (int i = 1; i < 9; i++)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i + 1][j - 1]) % 1000000000;
        }
        dp[9][j] = dp[8][j - 1];
    }

    long long answer = 0;
    for (int i = 0; i < 10; i++)
    {
        answer = (answer + dp[i][N]) % 1000000000;
    }

    cout << answer << "\n";
}
