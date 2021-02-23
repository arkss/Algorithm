#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int N, M;

vector<int> bigAdjust[101];
vector<int> smallAdjust[101];
int visited[101];

int cnt;

void bfs(int start, bool isBig)
{
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (isBig)
            for (int i = 0; i < bigAdjust[now].size(); i++)
            {
                int next = bigAdjust[now][i];
                if (!visited[next])
                {
                    visited[next] = 1;
                    cnt++;
                    q.push(next);
                }
            }
        else
            for (int i = 0; i < smallAdjust[now].size(); i++)
            {
                int next = smallAdjust[now][i];
                if (!visited[next])
                {
                    visited[next] = 1;
                    cnt++;
                    q.push(next);
                }
            }
    }
}

int main()
{
    int answer = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int big, small;
        cin >> big >> small;

        bigAdjust[big].push_back(small);
        smallAdjust[small].push_back(big);
    }

    for (int i = 1; i <= N; i++)
    {
        memset(visited, 0, sizeof(visited));
        cnt = 0;
        bfs(i, true);
        if (cnt > N / 2)
            answer++;
    }

    for (int i = 1; i <= N; i++)
    {
        memset(visited, 0, sizeof(visited));
        cnt = 0;
        bfs(i, false);
        if (cnt > N / 2)
            answer++;
    }

    cout << answer << "\n";
}