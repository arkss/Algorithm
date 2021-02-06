#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char board[52][52];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int visited[52][52];
int R, C;

pair<int, int> s;
queue<pair<pair<int, int>, int>> waters;

void spreate_water(int n)
{
    while (1)
    {
        pair<pair<int, int>, int> water = waters.front();
        if (water.second != n)
            break;

        waters.pop();

        int x = water.first.first;
        int y = water.first.second;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 > nx || nx >= R || 0 > ny || ny >= C)
                continue;

            if (board[nx][ny] == 'X' || board[nx][ny] == '*' || board[nx][ny] == 'D')
                continue;

            board[nx][ny] = '*';
            waters.push({{nx, ny}, n + 1});
        }
    }
}

int bfs()
{
    queue<pair<int, int>> q;
    q.push({s.first, s.second});
    visited[s.first][s.second] = 1;

    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();

        if (board[now.first][now.second] == 'D')
            return visited[now.first][now.second];

        spreate_water(visited[now.first][now.second]);

        for (int i = 0; i < 4; i++)
        {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if (0 > nx || nx >= R || 0 > ny || ny >= C)
                continue;

            if (board[nx][ny] == 'X' || board[nx][ny] == '*')
                continue;

            if (visited[nx][ny])
                continue;

            q.push({nx, ny});
            visited[nx][ny] = visited[now.first][now.second] + 1;
        }
    }

    return -1;
}

int main()
{

    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < C; j++)
        {
            board[i][j] = line[j];
            if (board[i][j] == '*')
                waters.push({{i, j}, 1});

            else if (board[i][j] == 'S')
                s = {i, j};
        }
    }

    int result = bfs();

    if (result == -1)
        cout << "KAKTUS\n";
    else
        cout << result - 1 << "\n";
}