#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 4

struct FISH
{
    int x, y;
    int dir;
    bool alive;
};

int answer;
// 물고기가 죽으면 -1
// 상어가 있는 곳은 -2
int board[SIZE][SIZE][2];
FISH f[17];

int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

void save_board_f(int temp_board[SIZE][SIZE][2], FISH temp_f[17])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            temp_board[i][j][0] = board[i][j][0];
            temp_board[i][j][1] = board[i][j][1];
            temp_f[i * 4 + (j + 1)] = f[i * 4 + (j + 1)];
        }
    }
}

void recover_board_f(int temp_board[SIZE][SIZE][2], FISH temp_f[17])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j][0] = temp_board[i][j][0];
            board[i][j][1] = temp_board[i][j][1];
            f[i * 4 + (j + 1)] = temp_f[i * 4 + (j + 1)];
        }
    }
}

void print_board()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout.width(2);
            cout << board[i][j][0] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void move_all_fish()
{
    for (int i = 1; i <= 16; i++)
    {
        if (!f[i].alive)
            continue;

        bool is_changed = false;
        int x = f[i].x;
        int y = f[i].y;
        int dir = f[i].dir;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (0 <= nx && nx < SIZE && 0 <= ny && ny < SIZE)
        {
            // 상어인 경우
            if (board[nx][ny][0] == -2)
                continue;
            // 두 물고기 교환 (board 최신화, F 최신화)

            // 1. 빈 칸인 경우
            else if (board[nx][ny][0] == -1)
            {
                f[i].x = nx;
                f[i].y = ny;
                board[nx][ny][0] = i;
                board[x][y][0] = -1;
            }
            // 2. 물고기가 존재하는 경우
            else
            {
                swap(f[i].x, f[board[nx][ny][0]].x);
                swap(f[i].y, f[board[nx][ny][0]].y);
                swap(board[x][y][0], board[nx][ny][0]);
                swap(board[x][y][1], board[nx][ny][1]);
            }
            is_changed = true;
        }
        int origin_dir = dir;
        while (!is_changed)
        {
            dir = (dir + 1) % 9;
            if (dir == 0)
                dir++;
            if (dir == origin_dir)
                break;
            nx = x + dx[dir];
            ny = y + dy[dir];

            if (0 <= nx && nx < SIZE && 0 <= ny && ny < SIZE)
            {
                // 상어인 경우
                if (board[nx][ny][0] == -2)
                    continue;
                // 두 물고기 교환 (board 최신화, F 최신화)
                // 1. 빈 칸인 경우
                else if (board[nx][ny][0] == -1)
                {
                    f[i].x = nx;
                    f[i].y = ny;
                    board[nx][ny][0] = i;
                    board[x][y][0] = -1;
                }
                else
                {
                    swap(f[i].x, f[board[nx][ny][0]].x);
                    swap(f[i].y, f[board[nx][ny][0]].y);
                    swap(board[x][y][0], board[nx][ny][0]);
                    swap(board[x][y][1], board[nx][ny][1]);
                }

                f[i].dir = dir;
                is_changed = true;
            }
        }
    }
    print_board();
}

void backtracking(int x, int y, int dir, int sum)
{
    answer = max(answer, sum);
    int temp_board[SIZE][SIZE][2];
    FISH temp_f[17];
    save_board_f(temp_board, temp_f);

    move_all_fish();

    for (int i = 1; i <= 3; i++)
    {
        int nx = x + dx[dir] * i;
        int ny = y + dy[dir] * i;
        if (0 <= nx && nx < SIZE && 0 <= ny && ny < SIZE)
        {
            if (board[nx][ny][0] == -1)
                continue;

            int f_num = board[nx][ny][0];
            board[nx][ny][0] = -2;
            board[x][y][0] = -1;
            f[f_num].alive = false;
            backtracking(nx, ny, board[nx][ny][1], sum + f_num);
            board[nx][ny][0] = f_num;
            board[x][y][0] = -2;
            f[f_num].alive = true;
        }
    }
    recover_board_f(temp_board, temp_f);
}

int main()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            int num, dir;
            cin >> num >> dir;
            board[i][j][0] = num;
            board[i][j][1] = dir;
            f[num] = {i, j, dir, true};
        }
    }

    int shake_eat = board[0][0][0];
    f[shake_eat].alive = false;
    board[0][0][0] = -2;
    backtracking(0, 0, f[shake_eat].dir, shake_eat);
    cout << answer << "\n";
}
