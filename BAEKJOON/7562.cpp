#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int visited[301][301];
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int bfs(pair<int, int> start, pair<int, int> end, int boardSize)
{
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = 1;

    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();

        int nowX = now.first;
        int nowY = now.second;

        if (nowX == end.first && nowY == end.second)
            return visited[nowX][nowY] - 1;

        for (int i = 0; i < 8; i++)
        {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];

            if (0 > nextX || nextX >= boardSize || 0 > nextY || nextY >= boardSize)
                continue;

            if (!visited[nextX][nextY])
            {
                visited[nextX][nextY] = visited[nowX][nowY] + 1;
                q.push({nextX, nextY});
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        memset(visited, 0, sizeof(visited));

        int boardSize;
        cin >> boardSize;

        pair<int, int> start, end;
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;

        cout << bfs(start, end, boardSize) << "\n";
    }
}
