#include <iostream>

using namespace std;

int board[101][101];
int visited[101][101];

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

void dfs(int r, int c, int n){
    
    visited[r][c] = -1;
    
    for (int i=0;i<4;i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0<=nr && nr<n && 0<=nc && nc<n){
            if (visited[nr][nc] == 0)
                dfs(nr,nc,n);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    
    int maxH = 0;
    
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> board[i][j];
            if (board[i][j] > maxH)
                maxH = board[i][j];
        }
    }

    
    int safeNumMax = 0;
    
    for (int h=0;h<=maxH;h++){
        // visited 초기화
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                // 물에 잠기면 -1 아니면 0
                if (board[i][j] <= h)
                    visited[i][j] = -1;
                else
                    visited[i][j] = 0;
            }
        }
        
        int safeNum = 0;
        
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (visited[i][j] == 0){
                    
                    safeNum++;
                    dfs(i,j,n);
                }
            }
        }
        
        safeNumMax = max(safeNumMax, safeNum);
    }
    
    cout << safeNumMax << "\n";
  
    return 0;
}
