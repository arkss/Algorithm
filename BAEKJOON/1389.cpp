#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

vector<int> neighbors[101];
int bacon[101][101];
int visited[101];

int bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    int sum = 0;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < neighbors[now].size(); i++)
        {
            int next = neighbors[now][i];
            if (!visited[next])
            {
                visited[next] = 1;
                bacon[start][next] = bacon[start][now] + 1;
                sum += bacon[start][next];
                q.push(next);
            }
        }
    }
    return sum;
}

void print_bacon(int N)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << bacon[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }

    int smallest_idx = 0;
    int smallest = 987654321;

    for (int i = 1; i <= N; i++)
    {
        int sum = bfs(i);
        if (smallest > sum)
        {
            smallest_idx = i;
            smallest = sum;
        }

        memset(visited, 0, sizeof(visited));
    }
    cout << smallest_idx << "\n";
}