#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 987654321

vector<pair<int, int>> graph[1001];
int dist[1001];
int visited[1001];

int N, M;
int start, destination;

void dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    pq.push({0, start});
    visited[start] = 1;

    while (!pq.empty())
    {
        int shortestDistance = -pq.top().first;
        int shortestNode = pq.top().second;
        pq.pop();

        //cout << "shortest: " << shortestNode << " " << shortestDistance << "\n";

        for (int i = 0; i < graph[shortestNode].size(); i++)
        {
            int nextNode = graph[shortestNode][i].first;
            int nextDistance = graph[shortestNode][i].second;

            //cout << "next: " << nextNode << " " << nextDistance << "\n";

            if (dist[nextNode] > shortestDistance + nextDistance)
            {
                dist[nextNode] = shortestDistance + nextDistance;
                pq.push({-dist[nextNode], nextNode});
            }
        }
        //cout << "\n";
    }
}

int main()
{

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back({e, w});
    }

    cin >> start >> destination;

    for (int i = 1; i <= N; i++)
        dist[i] = INF;

    dijkstra();

    cout << dist[destination] << "\n";
}