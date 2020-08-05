#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1: 드래곤커브
int board[101][101];

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

struct CURVE
{
    int x, y;
    int dir;
    int g;
};

vector<CURVE> curves;

void print_dragon_curve_point()
{
    cout << "\n\n";
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            if (board[i][j] == 1)
                cout << i << " " << j << "\n";
        }
    }
}

int check_dragon_box()
{
    int cnt = 0;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            if (board[i][j] + board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1] == 4)
                cnt++;

    return cnt;
}

void print_v(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}

void generate_dragon_curve(CURVE c)
{
    int x = c.x;
    int y = c.y;
    int dir = c.dir;
    int g = c.g;

    board[x][y] = 1;

    vector<int> dirs = {dir};

    for (int i = 0; i <= g; i++)
    {
        vector<int> before_dirs = dirs;
        reverse(before_dirs.begin(), before_dirs.end());
        for (int j = 0; j < before_dirs.size(); j++)
        {
            int ndir;
            if (i == 0)
                ndir = before_dirs[j];
            else
            {
                ndir = (before_dirs[j] + 1) % 4;
                dirs.push_back(ndir);
            }

            x = x + dx[ndir];
            y = y + dy[ndir];
            if (0 <= x && x <= 100 && 0 <= y && y <= 100)
                board[x][y] = 1;
        }
    }
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        CURVE c;
        cin >> c.y >> c.x >> c.dir >> c.g;
        curves.push_back(c);
        generate_dragon_curve(c);
    }

    //print_dragon_curve_point();

    int answer = check_dragon_box();

    cout << answer << "\n";
}