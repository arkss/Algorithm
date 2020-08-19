#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> computers;
vector<int> visited;
vector<int> adjust[10001];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < adjust[now].size(); i++)
        {
            int next = adjust[now][i];
            if (!visited[next])
            {
                visited[next] = 1;
                computers[next]++;
                q.push(next);
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    computers.resize(N + 1, 0);
    visited.resize(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int c1, c2;
        cin >> c1 >> c2;
        adjust[c1].push_back(c2);
    }

    for (int i = 1; i <= N; i++)
    {
        bfs(i);
        visited.clear();
        visited.resize(N + 1, 0);
    }

    vector<int> answer;
    int max_value = computers[1];

    for (int i = 1; i <= N; i++)
        max_value = max(max_value, computers[i]);
    for (int i = 1; i <= N; i++)
        if (computers[i] == max_value)
            cout << i << " ";
}