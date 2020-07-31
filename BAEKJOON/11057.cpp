#include <iostream>
#include <vector>

using namespace std;

int dp[1001][10];

int main()
{
    int answer = 0;
    int N;
    cin >> N;

    for (int i = 0; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++)
        for (int j = 0; j < 10; j++)
            for (int k = j; k < 10; k++)
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;

    for (int i = 0; i < 10; i++)
    {
        answer = (answer + dp[N][i]) % 10007;
    }

    cout << answer << "\n";
}