#include <iostream>
#include <typeinfo>

using namespace std;

char board[21][21];
bool visited[26];

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
int max_move = 1;

void print_visited()
{
    for (int i = 0; i < 26; i++)
    {
        cout << visited[i] << " ";
    }
    cout << "\n";
}

void dfs(int R, int C, int r, int c, int cnt)
{
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 <= nr && nr < R && 0 <= nc && nc < C)
            if (!(visited[board[nr][nc] - 'A']))
            {
                visited[board[nr][nc] - 'A'] = 1;
                dfs(R, C, nr, nc, cnt + 1);
                visited[board[nr][nc] - 'A'] = 0;
            }
    }
    max_move = max(max_move, cnt);
}

void print_board(int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int R, C;
    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < row.size(); j++)
        {
            board[i][j] = row[j];
        }
    }
    visited[board[0][0] - 'A'] = 1;
    dfs(R, C, 0, 0, 1);
    cout << max_move << "\n";
}