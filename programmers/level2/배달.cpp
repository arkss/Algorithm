#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

vector<vector<pair<int, int>>> adjust;
vector<int> dist;

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        int nowDist = -pq.top().first;
        int nowNode = pq.top().second;
        pq.pop();

        for (int i = 0; i < adjust[nowNode].size(); i++)
        {
            int cost = nowDist + adjust[nowNode][i].second;

            if (cost < dist[adjust[nowNode][i].first])
            {
                dist[adjust[nowNode][i].first] = cost;
                pq.push({-cost, adjust[nowNode][i].first});
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;
    adjust.resize(N + 1);
    dist.resize(N + 1, INF);

    for (int i = 0; i < road.size(); i++)
    {
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];

        adjust[a].push_back({b, c});
        adjust[b].push_back({a, c});
    }

    dijkstra(1);

    for (int i = 1; i <= N; i++)
    {
        if (dist[i] <= K)
            answer++;
    }

    return answer;
}

int main() {}