#include <iostream>
#include <string>

using namespace std;

int board[10002][10002];

// (dir) 0: 오른쪽, 1: 위, 2: 왼쪽, 3: 아래
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

void print_board(int r1, int c1, int r2, int c2, int max_size)
{
    cout << "\n\n";
    for (int i = r1; i <= r2; i++)
    {
        for (int j = c1; j <= c2; j++)
        {
            cout.width(max_size);
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

int max4(int a, int b, int c, int d)
{
    return max(max(a, b), max(c, d));
}

int main()
{
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    r1 = r1 + 5000;
    c1 = c1 + 5000;
    r2 = r2 + 5000;
    c2 = c2 + 5000;

    int x = 5000;
    int y = 5000;
    int num = 1;
    int dir = 0;

    for (int i = 0; i < 11 * 11; i++)
    {
        //cout << x - 5000 << " " << y - 5000 << " " << num << "\n";
        board[x][y] = num++;
        x = x + dx[dir];
        y = y + dy[dir];

        int ox = x - 5000;
        int oy = y - 5000;

        // 방향 전환하는 지점들
        if ((oy > 0 && oy - ox == 1) || oy * (-1) == ox || (oy < 0 && oy == ox))
            dir = (dir + 1) % 4;
    }
    //cout << to_string(board[r1 + 5000][c1 + 5000]).size() << "\n";
    int max_size = max4(to_string(board[r1][c1]).size(), to_string(board[r1][c2]).size(), to_string(board[r2][c1]).size(), to_string(board[r2][c2]).size());
    //cout << max_size << "\n";
    print_board(r1, c1, r2, c2, max_size);
}