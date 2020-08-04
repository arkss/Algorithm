#include <iostream>

using namespace std;

int board[1002][1002];
//int dp[1002][1002];

int max3(int a, int b, int c)
{
    return max(a, max(b, c));
}

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> board[i][j];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            board[i][j] = board[i][j] + max3(board[i - 1][j], board[i][j - 1], board[i - 1][j - 1]);

    cout << board[N][M] << "\n";
}