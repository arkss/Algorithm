#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int visited[101];
vector<int> v[101];

int bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = 0;
    
    int result = 0;
    
    while (!q.empty()){
        int now = q.front();
        q.pop();
        result += visited[now];
        for (int next:v[now]){
            if (visited[next] == -1){
                visited[next] = visited[now] + 1;
                q.push(next);
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    int N,M;
    cin >> N >> M;
    
    for (int i=0;i<M;i++){
        int n1, n2;
        cin >> n1 >> n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    
    int minNum = 987654321;
    int answer = 0;
    
    for (int i=1;i<=N;i++){
        memset(visited, -1, sizeof(int)*(N+1));
        for (int j=0;j<N;j++){
            if (visited[j] != -1){
                cout << "error" << "\n";
            }
        }
        int result = bfs(i);
        if (result < minNum){
            minNum = result;
            answer = i;
        }
    }
    
    cout << answer << "\n";

    return 0;
}
