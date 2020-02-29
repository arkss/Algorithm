#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 999999999

using namespace std;

vector<pair<int, int> > adj[20001];
int dist[20001][3];
bool closed[20001][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int v, e;
    cin >> v >> e;  // v: # of vertices, e: # of edges.
    
    
    for(int i=0; i<e; i++) {
        int u, v, w;
        cin >> u >> v >> w;  // u -> v. w: weight <= 10. u != v.
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    int k = 1; // k: start vertex.
    int m1, m2;
    cin >> m1 >> m2;
    
    for (int i=0;i<v+1;i++){
        fill_n(dist[i], 3, INF);
    }
    
    dist[k][0] = 0;
    dist[m1][1] = 0;
    dist[m2][2] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq[3];  // (dist, vertex)
    pq[0].push({0, k});
    pq[1].push({0,m1});
    pq[2].push({0,m2});
    
    for (int i=0;i<3;i++){
        while(!pq[i].empty()) {
            pair<int, int> top_pair = pq[i].top(); pq[i].pop();
            int now = top_pair.second, now_dist = top_pair.first;
            
            if(closed[now][i]) continue;
            closed[now][i] = true;
            
            for(pair<int, int> next_pair : adj[now]) {
                int next = next_pair.first, weight = next_pair.second;
                if(!closed[next][i] && dist[next][i] > now_dist + weight) {
                    dist[next][i] = now_dist + weight;
                    pq[i].push({dist[next][i], next});
                }
            }
        }
    }
    int load1 ,load2;
    // 1 -> m1 -> m2 -> v
    if (dist[m1][0] == INF || dist[m2][1] == INF || dist[v][2] == INF){
        load1 = INF;
    }
    else {
        load1 = dist[m1][0] + dist[m2][1] + dist[v][2];
    }
    // 1 -> m2 -> m1 -> v
    if (dist[m2][0] == INF || dist[m1][2] == INF || dist[v][1] == INF){
        load2 = INF;
    }
    else {
        load2 = dist[m2][0] + dist[m1][2] + dist[v][1];
    }
    
    if (load1 == INF && load2 == INF) cout << "-1\n";
    else cout << min(load1, load2);
    
    
    return 0;
}


