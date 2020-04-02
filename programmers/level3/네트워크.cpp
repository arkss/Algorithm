#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool visited[201];

void dfs(int com_num, int n, vector<vector<int>> computers){
    visited[com_num] = 1;
    for (int i=0;i<n;i++){
        if (!visited[i] && computers[com_num][i])
            dfs(i, n, computers);
    }
}

int solution(int n, vector<vector<int>> computers){
    int answer = 0;
    memset(visited, 0, sizeof(visited));
    for (int i=0;i<n;i++){
        if(!visited[i]) {
            dfs(i,n, computers);
            answer++;
        }
    }

    return answer;
}

int main(){
    cout << solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) << "\n";
    return 0;
}