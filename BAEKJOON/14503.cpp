#include <iostream>

using namespace std;
// 벽이면 1, 청소한 공간 2, 청소 안한 공간 0
int board[51][51];
int answer;

// 북 동 남 서
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int r, int c, int dir)
{
    // 청소
    if (!board[r][c])
    {
        board[r][c] = 2;
        answer++;
    }
    for (int i = 0; i < 4; i++)
    {
        // 왼쪽 방향의 공간
        int nr = r + dx[(dir + 3) % 4];
        int nc = c + dy[(dir + 3) % 4];
        if (!board[nr][nc])
        {
            dfs(nr, nc, (dir + 3) % 4);
            return;
        }
        else
            dir = (dir + 3) % 4;
    }

    // 네 방향 다 청소, 벽 -> 한 칸 후진
    int nr = r + dx[(dir + 2) % 4];
    int nc = c + dy[(dir + 2) % 4];
    if (board[nr][nc] != 1)
    {
        dfs(nr, nc, dir);
    }
}
int main()
{
    int N, M;
    cin >> N >> M;
    int r, c, dir;
    cin >> r >> c >> dir;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }
    dfs(r, c, dir);
    cout << answer << "\n";
}