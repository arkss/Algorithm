#include <iostream>

using namespace std;
// 빈칸은 0, 벽은 1
int board[17][17];
int N;
int answer;

// 우, 세로, 대각
int dx[] = {0, 1, 1};
int dy[] = {1, 0, 1};

bool is_valid(int x, int y)
{
    return 1 <= x && x <= N && 1 <= y && y <= N;
}

//pipe_num 0: 가로 1: 세로 2: 대각선
void make_pipe(int x, int y, int pipe_num)
{
    if (x == N && y == N)
    {
        answer++;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (pipe_num == 0 && i == 1)
            continue;
        if (pipe_num == 1 && i == 0)
            continue;

        int nx = x + dx[i];
        int ny = y + dy[i];

        if (!is_valid(nx, ny))
            continue;

        if (board[nx][ny])
            continue;

        if (i == 2)
            if (board[x + 1][y] || board[x][y + 1])
                continue;

        make_pipe(nx, ny, i);
    }
}

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> board[i][j];
        }
    }

    make_pipe(1, 2, 0);

    cout << answer << "\n";
}