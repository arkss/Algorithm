#include <iostream>

using namespace std;

int board[501][501];
// dp[i][j] : i,j 부터 시작했을 경우 판다가 살 수 있는 일수
int dp[501][501];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int longest;

void dfs(int n, int x, int y, int cnt)
{
    // if (cnt == 1)
    // {
    //     cout << x << " " << y << "에서 시작\n";
    // }
    // cout << x << " " << y << " " << cnt << "\n";
    longest = max(longest, cnt);
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n)
        {
            if (board[nx][ny] > board[x][y])
            {
                if (dp[nx][ny])
                    longest = max(longest, dp[nx][ny] + 1);
                else
                    dfs(n, nx, ny, cnt + 1);
            }
        }
    }
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
            dfs(n, i, j, 1);
            dp[i][j] = longest;
            answer = max(answer, dp[i][j]);
            longest = 0;
        }
    }

    print_dp(n);

    cout << answer << "\n";
}