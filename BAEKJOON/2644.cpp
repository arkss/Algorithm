// 9
// 7 3
// 7
// 1 2
// 1 3
// 2 7
// 2 8
// 2 9
// 4 5
// 4 6

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adjust[101];
int visited[101];
int p1, p2;
int answer = -1;

void bfs()
{
    queue<int> q;
    q.push(p1);
    visited[p1] = 1;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (now == p2)
        {
            answer = visited[now] - 1;
            break;
        }

        for (int i = 0; i < adjust[now].size(); i++)
        {
            int next = adjust[now][i];
            if (!visited[next])
            {
                visited[next] = visited[now] + 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;

    cin >> p1 >> p2;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int parent, child;
        cin >> parent >> child;

        adjust[parent].push_back(child);
        adjust[child].push_back(parent);
    }

    bfs();

    cout << answer << "\n";
}