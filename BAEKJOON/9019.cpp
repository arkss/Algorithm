#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int num, goal;
int visited[10000];

string bfs()
{
    // 현재의 수, 현재의 수까지 명령어
    queue<pair<int, string>> q;
    q.push({num, ""});
    visited[num] = 1;

    while (!q.empty())
    {
        pair<int, string> now = q.front();
        int nowNum = now.first;
        string nowStr = now.second;
        q.pop();

        if (nowNum == goal)
            return nowStr;

        // D
        int calNum = nowNum * 2 % 10000;
        if (!visited[calNum])
        {
            visited[calNum] = 1;
            q.push(make_pair(calNum, nowStr + "D"));
        }

        // S
        calNum = (nowNum == 0) ? 9999 : nowNum - 1;
        if (!visited[calNum])
        {
            visited[calNum] = 1;
            q.push(make_pair(calNum, nowStr + "S"));
        }

        // L
        calNum = (nowNum % 1000) * 10 + nowNum / 1000;
        if (!visited[calNum])
        {
            visited[calNum] = 1;
            q.push(make_pair(calNum, nowStr + "L"));
        }

        // R
        calNum = (nowNum % 10) * 1000 + nowNum / 10;
        if (!visited[calNum])
        {
            visited[calNum] = 1;
            q.push(make_pair(calNum, nowStr + "R"));
        }
    }

    return "";
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> num >> goal;
        memset(visited, 0, sizeof(visited));
        cout << bfs() << "\n";
    }
}