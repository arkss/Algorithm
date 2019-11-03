#include <iostream>
#include <cstring>

using namespace std;

int board[301][301];
int temp[301][301];
int visited[301][301];

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

void dfs(int r,int c,int N,int M){
    // 방문 체크
    visited[r][c] = 1;
    // 빙하를 하나씩 녹이면 이에 다른 빙하가 영향을 받으므로 얼만큼 녹는지 기억했다가 한꺼번에 녹인다.
    for (int i=0;i<4;i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0<=nr && nr<N && 0<=nc && nc<=M){
            if(board[nr][nc] == 0){
                temp[r][c]--;
            }
        }
    }
    
    for (int i=0;i<4;i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0<=nr && nr<N && 0<=nc && nc<=M){
            if (board[nr][nc]&&!visited[nr][nc]){
                dfs(nr,nc,N,M);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int N,M;
    cin >> N >> M;
    
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> board[i][j];
        }
    }
    
    int year = 0;

    while (1){
        memset(visited, 0, sizeof(visited));
        memset(temp, 0, sizeof(temp));
       
        
        int dfs_count = 0;
        int dfs_flag = 0;
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                if (board[i][j]!=0 && !visited[i][j]){
                    dfs(i,j,N,M);
                    dfs_count++;
                    if (dfs_count == 2) {
                        dfs_flag = 1;
                        break;
                    }
                }
            }
            if (dfs_flag) break;
        }
        if (dfs_flag) break;
        
        // 빙하가 모두 녹은 경우
        if (dfs_count == 0){
           year = 0;
            break;
        }
            
        
        // 빙하를 한 번에 녹이기
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                board[i][j] += temp[i][j];
                if (board[i][j] < 0) board[i][j] = 0;
            }
        }
        
        year++;
    }
    cout << year << "\n";
    
    return 0;
}
