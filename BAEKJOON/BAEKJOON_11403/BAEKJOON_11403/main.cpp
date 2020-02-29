#include <iostream>

using namespace std;

int arr[100][100];

// 1이면 이미 탐색한 경로, 0이면 탐색 전 경로
int visited[100][100];

int bfs(int i, int j, int N)
{
    arr[i][j] = 1;
    // 방문 표시
    visited[i][j] = 1;
    for (int k=0;k<N;k++){
        // 경로가 있고 방문을 안했으면 탐색
        if (arr[j][k] && !visited[i][k])
            
            bfs(i,k,N);
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int N;
    
    cin >> N;
    
    int i,j;
    for (i=0;i<N;i++){
        for(j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    
    for (i=0;i<N;i++){
        for(j=0;j<N;j++){
            // 경로가 있고 방문을 안했으면 탐색
            if (arr[i][j] && !visited[i][j])
                bfs(i,j,N);
        }
    }
    
    for (i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ",arr[i][j]);
        }
        cout << endl;
    }
}
