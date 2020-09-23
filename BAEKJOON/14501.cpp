#include <iostream>

using namespace std;

int board[2][16];
int dp[16];

int main()
{
    int N;
    cin >> N;

    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> board[0][i] >> board[1][i];
    }

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int t = board[0][j];
            int p = board[1][j];
            if (t + j <= i)
            {
                dp[i] = max(dp[i], dp[j] + p);
            }
        }
    }

    // for (int i = 0; i <= N; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";

    cout << dp[N] << "\n";
}
