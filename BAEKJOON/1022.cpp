#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int board[50][5];

// (dir) 0: 오른쪽, 1: 위, 2: 왼쪽, 3: 아래
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

void print_board(int r1, int c1, int r2, int c2, int max_size)
{
    for (int i = 0; i <= r2 - r1; i++)
    {
        for (int j = 0; j <= c2 - c1; j++)
        {
            cout.width(max_size);
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int x = 0;
    int y = 0;
    int num = 1;
    int dir = 0;

    int max_size = 0;

    for (int i = 0; i < 10001 * 10001; i++)
    {

        if (r1 <= x && x <= r2 && c1 <= y && y <= c2)
        {
            board[x - r1][y - c1] = num;
            max_size = max(max_size, to_string(num).size());
        }
        num++;
        x = x + dx[dir];
        y = y + dy[dir];

        // 방향 전환하는 지점들
        if ((y > 0 && y - x == 1) || y * (-1) == x || (y < 0 && y == x))
            dir = (dir + 1) % 4;
    }
    print_board(r1, c1, r2, c2, max_size);
}