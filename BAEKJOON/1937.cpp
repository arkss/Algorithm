#include <iostream>

using namespace std;

int board[501][501];
// dp[i][j] : i,j 부터 시작했을 경우 판다가 살 수 있는 일수
int dp[501][501];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dfs(int n, int x, int y)
{
    dp[x][y] = 1;
    // if (cnt == 1)
    // {
    //     cout << x << " " << y << "에서 시작\n";
    // }
    // cout << x << " " << y << " " << cnt << "\n";

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n)
        {
            if (board[nx][ny] > board[x][y])
            {
                if (dp[nx][ny])
                    dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);
                else
                    dp[x][y] = max(dp[x][y], dfs(n, nx, ny) + 1);
            }
        }
    }
    return dp[x][y];
}

void print_dp(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

int main()
{
    int answer = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            answer = max(answer, dfs(n, i, j));
        }
    }

    //print_dp(n);

    cout << answer << "\n";
}