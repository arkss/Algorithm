#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int board[302][302];
int dp[302][302];
int N, M;
int maxCnt = 0;

int max3(int a, int b, int c)
{
    return max(max(a, b), c);
}

int main()
{

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> board[i][j];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            dp[i][j] = max3(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + board[i][j];

    cout << dp[N][M] << "\n";
}