#include <iostream>
#include <set>

using namespace std;

int BOARD_SIZE = 5;
int board[5][5];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
set<string> answer;

void backtracking(int r, int c, string s, int cnt)
{

    if (cnt == 6)
    {
        answer.insert(s);
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 <= nr && nr <= 4 && 0 <= nc && nc <= 4)
            {
                s += to_string(board[nr][nc]);
                backtracking(nr, nc, s, cnt + 1);
                s = s.substr(0, s.size() - 1);
            }
        }
    }
}

int main()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            backtracking(i, j, to_string(board[i][j]), 1);
        }
    }

    cout << answer.size() << "\n";
}
