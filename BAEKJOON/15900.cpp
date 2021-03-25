#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adjust[500001];
int visited[500001];
int totalDistance;

// 방법 1
void bfs(int start)
{
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = 1;

    while (!q.empty())
    {
        pair<int, int> now = q.front();
        int nowNode = now.first;
        int nowDistance = now.second;

        //cout << nowNode << " " << nowDistance << "\n";
        q.pop();

        bool isLeaf = true;
        for (int i = 0; i < adjust[nowNode].size(); i++)
        {
            if (!visited[adjust[nowNode][i]])
            {
                isLeaf = false;
                q.push({adjust[nowNode][i], nowDistance + 1});
                visited[adjust[nowNode][i]] = 1;
            }
        }

        if (isLeaf)
            totalDistance += nowDistance;
    }
}

// 방법 2
void dfs(int start, int cnt)
{
    if (start != 1 && adjust[start].size() == 1)
    {
        totalDistance += cnt;
        return;
    }

    for (int i = 0; i < adjust[start].size(); i++)
    {

        if (!visited[start])
        {
            visited[start] = 1;
            dfs(adjust[start][i], cnt + 1);
            visited[start] = 0;
        }
    }
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;

        adjust[node1].push_back(node2);
        adjust[node2].push_back(node1);
    }

    bfs(1);
    // dfs(1, 0);

    if (totalDistance % 2 == 0)
        cout << "No\n";
    else
        cout << "Yes\n";
}