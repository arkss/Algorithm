#include <iostream>
#include <queue>

using namespace std;

int visited[200001];

int bfs(int N, int K)
{
    queue<pair<int, int>> q;
    q.push({N, 0});
    visited[N] = 1;

    while (!q.empty())
    {

        pair<int, int> now = q.front();
        // cout << now.first << "\n";

        if (now.first == K)
            return now.second;

        q.pop();
        int sec = now.second + 1;
        int next;
        next = now.first - 1;

        if (next > 0 && next < 200000 && !visited[next])
        {
            visited[next] = 1;
            q.push({next, sec});
        }

        next = now.first + 1;

        if (next > 0 && next < 200000 && !visited[next])
        {
            visited[next] = 1;
            q.push({next, sec});
        }
        next = now.first * 2;

        if (next > 0 && next < 200000 && !visited[next])
        {
            visited[next] = 1;
            q.push({next, sec});
        }
    }
}

int main()
{
    int N, K;
    cin >> N >> K;

    if (N == K)
        cout << 0 << "\n";
    else if (N > K)
        cout << N - K << "\n";
    else
        cout << bfs(N, K) << "\n";
}