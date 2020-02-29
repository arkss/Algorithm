#include <iostream>

using namespace std;

int board[50][50];

int cnt;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void dfs(int y,int x, int M, int N){

    board[y][x] = 0;
    
    for (int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (0<=nx && nx<M && 0<= ny && ny<N){
            if (board[ny][nx]){
                dfs(ny,nx,M,N);
            }
        }
    }
    
}

void init(int M, int N){
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            board[i][j] = 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    while (T--){
        
        // M : 가로, N : 세로
        int M,N,K;
        cin >> M >> N >> K;
        
        
        init(M,N);
        
        for (int i=0;i<K;i++){
            int x,y;
            cin >> x >> y;
            board[y][x] = 1;
        }

        cnt = 0;
        
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                if (board[i][j]){
                    cnt++;
                    dfs(i,j,M,N);
                }
            }
        }
        cout << cnt << "\n";
        
    }
    return 0;;
}
