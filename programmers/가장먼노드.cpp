#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 인접리스트
vector<int> v[20001];
// 최단거리
int check[20001];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    check[1] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int i = 0; i < v[node].size(); i++)
        {
            int next = v[node][i];
            if (check[next] == -1)
            {
                check[next] = check[node] + 1;
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge)
{
    int answer;
    for (int i = 0; i < edge.size(); i++)
    {
        int start = edge[i][0];
        int end = edge[i][1];
        v[start].push_back(end);
        v[end].push_back(start);
    }
    // 최단 거리 -1로 초기화
    for (int i = 1; i <= n; i++)
    {
        check[i] = -1;
    }

    bfs(1);
    int longest = 0;
    for (int i = 1; i <= n; i++)
    {
        if (longest < check[i])
        {
            longest = check[i];
            answer = 1;
        }
        else if (longest == check[i])
            answer++;
    }
    return answer;
}

int main()
{
    int n = 6;
    vector<vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
    cout << solution(n, edge) << "\n";
    return 0;
}