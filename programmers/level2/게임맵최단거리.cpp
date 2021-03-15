#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void print_visited(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}

int bfs(int x, int y, int n, int m, vector<vector<int>> maps)
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

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (visited[nx][ny])
                continue;

            if (!maps[nx][ny])
                continue;

            visited[nx][ny] = visited[now.first][now.second] + 1;
            q.push({nx, ny});
            if (nx == n - 1 && ny == m - 1)
                return visited[nx][ny];
        }
    }

    return -1;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;

    int n = maps.size();
    int m = maps[0].size();

    answer = bfs(0, 0, n, m, maps);
    //print_visited(n, m);
    return answer;
}

int main()
{
}