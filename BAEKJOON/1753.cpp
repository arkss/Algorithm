#include <iostream>
#include <queue>

using namespace std;

#define INF 987654321

// <끝점, 가중치>
vector<pair<int, int>> board[20001];
//int board[20001][20001];
int visited[20001];
int dist[20001];
int V, E;
int start;

void print_dist()
{
    for (int i = 1; i <= V; i++)
        cout << dist[i] << " ";
    cout << "\n";
}
/*
int find_shortest_node()
{
    int minDistance = INF;
    int minIndex;

    for (int i = 1; i <= V; i++)
    {
        if (visited[i])
            continue;
        if (dist[i] < minDistance)
        {
            minDistance = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void update_dist(int node)
{
    for (int i = 1; i <= V; i++)
    {
        if (visited[i])
            continue;
        if (!board[node][i])
            continue;
        if (dist[i] > dist[node] + board[node][i])
            dist[i] = dist[node] + board[node][i];
    }
}

void dijkstra()
{
    for (int i = 1; i <= V; i++)
    {
        if (board[start][i])
            dist[i] = board[start][i];
    }
    //print_dist();

    dist[start] = 0;
    visited[start] = 1;

    for (int i = 0; i < V - 1; i++)
    {
        int shortestNode = find_shortest_node();

        visited[shortestNode] = 1;
        update_dist(shortestNode);
        //print_dist();
    }
}
*/
void dijkstraWithHeap()
{
    //
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        int shortestNode = pq.top().second;
        int shortestWeight = -pq.top().first;
        pq.pop();

        for (int i = 0; i < board[shortestNode].size(); i++)
        {
            int node = board[shortestNode][i].first;
            int weight = board[shortestNode][i].second;

            if (dist[node] > shortestWeight + weight)
            {
                dist[node] = shortestWeight + weight;
                pq.push({-dist[node], node});
            }
        }
    }
}

int main()
{

    cin >> V >> E;
    cin >> start;

    for (int i = 0; i < E; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;

        board[s].push_back({e, w});
    }

    for (int i = 1; i <= V; i++)
        dist[i] = INF;

    //dijkstra();
    dijkstraWithHeap();
    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}