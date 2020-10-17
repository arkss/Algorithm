#include <iostream>

using namespace std;
// 빈칸은 0, 벽은 1
int board[17][17];
int N;
int answer;

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

    if (pipe_num == 0)
    {
        if (is_valid(x, y + 1) && !board[x][y + 1])
            make_pipe(x, y + 1, 0);
        if (is_valid(x + 1, y + 1) && !board[x + 1][y + 1] && !board[x][y + 1] && !board[x + 1][y])
            make_pipe(x + 1, y + 1, 2);
    }

    else if (pipe_num == 1)
    {
        if (is_valid(x + 1, y) && !board[x + 1][y])
            make_pipe(x + 1, y, 1);
        if (is_valid(x + 1, y + 1) && !board[x + 1][y + 1] && !board[x][y + 1] && !board[x + 1][y])
            make_pipe(x + 1, y + 1, 2);
    }

    else
    {
        if (is_valid(x, y + 1) && !board[x][y + 1])
            make_pipe(x, y + 1, 0);
        if (is_valid(x + 1, y) && !board[x + 1][y])
            make_pipe(x + 1, y, 1);
        if (is_valid(x + 1, y + 1) && !board[x + 1][y + 1] && !board[x][y + 1] && !board[x + 1][y])
            make_pipe(x + 1, y + 1, 2);
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