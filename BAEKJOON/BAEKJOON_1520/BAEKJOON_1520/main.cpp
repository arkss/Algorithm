#include <iostream>

using namespace std;

int N,M;
int board[501][501];
long long dp[501][501];

// 오른, 왼, 아래, 위
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

long long go(int x, int y){
    if (x==N-1 && y== M-1) return 1;
    if (dp[x][y] != -1){
        return dp[x][y];
    }

    dp[x][y]  = 0;

    for (int k=0;k<4;k++){
        int nx = x+dx[k];
        int ny = y+dy[k];
        if (0 <= nx && nx < N && 0 <= ny && ny < M){
            if (board[x][y] > board[nx][ny])
                dp[x][y] += go(nx,ny);
        }
    }
    return dp[x][y];
}


int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> board[i][j];
            dp[i][j] = -1;
        }
    }
    
    cout << go(0,0) << "\n";
    return 0;
}
