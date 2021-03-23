#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int board[101][101];
int visited[101][101];
int N, M, K;
int cnt;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

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

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            if (!board[nx][ny])
                continue;

            if (visited[nx][ny])
                continue;

            visited[nx][ny] = 1;
            q.push({nx, ny});
            cnt++;
        }
    }
}

int main()
{
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        board[--x][--y] = 1;
    }
    int maxCnt = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] && !visited[i][j])
            {
                cnt = 1;
                bfs(i, j);
                maxCnt = max(maxCnt, cnt);
            }
        }
    }

    cout << maxCnt << "\n";
}