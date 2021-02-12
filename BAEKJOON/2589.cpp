#include <iostream>
#include <queue>

using namespace std;

// W: 0, L: 1
int board[51][51];
int visited[51][51];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int maxLength;
int L, W;

void print_visited()
{
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if (0 <= nx && nx < L && 0 <= ny && ny < W)
            {
                if (visited[nx][ny])
                    continue;

                if (board[nx][ny] == 0)
                    continue;

                q.push({nx, ny});
                visited[nx][ny] = visited[now.first][now.second] + 1;
                maxLength = max(maxLength, visited[nx][ny]);
            }
        }
    }
}

void init_visited()
{
    for (int i = 0; i < L; i++)
        for (int j = 0; j < W; j++)
            visited[i][j] = 0;
}

int main()
{

    cin >> L >> W;

    for (int i = 0; i < L; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < W; j++)
        {
            board[i][j] = (s[j] == 'W') ? 0 : 1;
        }
    }

    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (board[i][j] == 1)
            {
                bfs(i, j);
                //print_visited();
                init_visited();
            }
        }
    }

    cout << maxLength - 1 << "\n";
}