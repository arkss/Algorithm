#include <iostream>

using namespace std;

int arr[1001][1001];
int visited[1001];

void dfs(int i, int N){
    
    for (int j=1;j<=N;j++){
        if (arr[i][j]&&!visited[j]){
            visited[j] = 1;
            dfs(j,N);
        }
    }
}

int main(int argc, const char * argv[]) {
    int N,M;
    cin >> N >> M;
    
    for (int i=0;i<M;i++){
        int node1, node2;
        cin >> node1 >> node2;
        
        arr[node1][node2] = 1;
        arr[node2][node1] = 1;
    }
    
    int cnt = 0;
    
    for (int i=1;i<=N;i++){
        if (!visited[i]){
            cnt++;
            visited[i] = 1;
            dfs(i,N);
        }
    }
    
    cout << cnt << "\n";
    
    return 0;
}
