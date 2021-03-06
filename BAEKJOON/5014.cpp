#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
int visited[1000001];

int bfs()
{
    queue<int> q;
    q.push(S);
    visited[S] = 1;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (now == G)
            return visited[now];

        // 위로 가기
        if (now + U <= F && !visited[now + U])
        {
            visited[now + U] = visited[now] + 1;
            q.push(now + U);
        }

        // 아래로 가기
        if (now - D >= 1 && !visited[now - D])
        {
            visited[now - D] = visited[now] + 1;
            q.push(now - D);
        }
    }

    return -1;
}

int main()
{
    // 총 층수, 현재 층, 목표 층, 위로 이동 수, 아래로 이동 수

    cin >> F >> S >> G >> U >> D;

    int rst = bfs();

    if (rst == -1)
        cout << "use the stairs\n";
    else
        cout << rst - 1 << "\n";
}