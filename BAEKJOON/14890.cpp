#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

// 경사로 : -1
int board[101][101];

// RIGHT, DOWN, LEFT, UP
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void print_board(int N)
{
    cout << "\n\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout.width(2);
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

bool go_straight(int x, int y, int dir, int N, int L)
{
    int nx, ny;
    int flat_cnt = 1;
    for (int i = 0; i < N - 1; i++)
    {
        nx = x + dx[dir];
        ny = y + dy[dir];

        // 2개 차이나면 종료
        if (abs(board[nx][ny] - board[x][y]) > 1)
            return false;
        // 같으면 진행
        else if (board[nx][ny] - board[x][y] == 0)
            flat_cnt++;

        // 1개 차이나며 올라가는 경우
        else if (board[nx][ny] - board[x][y] == 1)
        {
            // 경사로를 놓을 공간이 있는 경우
            if (flat_cnt >= L)
                flat_cnt = 1;
            else
                return false;
        }

        // 1개 차이나며 내려가는 경우
        else if (board[nx][ny] - board[x][y] == -1)
        {
            for (int j = 0; j < L - 1; j++)
            {
                int tmp_x = nx + dx[dir];
                int tmp_y = ny + dy[dir];

                if (tmp_x == N || tmp_y == N)
                    return false;
                if (board[nx][ny] != board[tmp_x][tmp_y])
                    return false;
                nx = tmp_x;
                ny = tmp_y;
            }
            i += L - 1;
            flat_cnt = 0;
        }
        x = nx;
        y = ny;
    }
    return true;
}

int main()
{
    int load_cnt = 0;
    int N, L;

    cin >> N >> L;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    bool is_success;
    for (int i = 0; i < N; i++)
    {
        is_success = go_straight(i, 0, RIGHT, N, L);
        load_cnt += is_success;
        is_success = go_straight(0, i, DOWN, N, L);
        load_cnt += is_success;
    }

    cout << load_cnt << "\n";
}