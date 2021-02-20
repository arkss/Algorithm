#include <iostream>
#include <queue>

using namespace std;

int M, N;
int board[251][251];
int visited[251][251];

int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if (0 > nx || nx >= M || 0 > ny || ny >= N)
                continue;

            if (visited[nx][ny])
                continue;

            if (!board[nx][ny])
                continue;

            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

int main()
{

    cin >> M >> N;
    int answer = 0;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] && !visited[i][j])
            {
                bfs(i, j);
                answer++;
            }
        }

    cout << answer << "\n";
}