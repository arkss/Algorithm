#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100 + 1;
const int INF = 100000 + 1;

int N, M;

int graph[MAX][MAX];

void floyd(void){
    //via번째 도시를 거쳐가는게 더 빠를 경우 update
    for (int via = 1; via <= N; via++){
        for (int start = 1; start <= N; start++){
            if (graph[start][via] == 0)
                continue;
            for (int end = 1; end <= N; end++){
                if (graph[via][end] == 0 || start == end)
                    continue;
                if (graph[start][end] == 0 || graph[start][end] > graph[start][via] + graph[via][end])
                    
                    graph[start][end] = graph[start][via] + graph[via][end];
            }
        }
    }
}

int main(void){
    
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        int start, end, cost;
        cin >> start >> end >> cost;

        if (!graph[start][end])
            graph[start][end] = cost;
        else
            graph[start][end] = min(graph[start][end], cost);
    }
    floyd();

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++)
            cout << graph[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
