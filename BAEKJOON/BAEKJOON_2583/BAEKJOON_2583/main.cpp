#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[100][100];

int dx[] ={0,0,1,-1};
int dy[] ={1,-1,0,0};

int cnt = 0;

void dfs(int y,int x, int M, int N){
    
    board[y][x] = 1;
    cnt++;
    
    for (int a=0;a<4;a++){
        int nx = x + dx[a];
        int ny = y + dy[a];
        if (0<=nx && nx<N && 0<=ny && ny<M)
            if (board[ny][nx]==0)
                dfs(ny,nx,M,N);
    }
}

int main(int argc, const char * argv[]) {
    
    int M,N,K;
    
    cin >> M >> N >> K;
    
    for (int i=0;i<K;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        for (int x=x1;x<x2;x++){
            for (int y=y1;y<y2;y++){
                board[y][x] = 1;
            }
        }
    }
    
    vector <int> v;

    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            if (!board[i][j]){
                cnt = 0;
                dfs(i,j,M,N);
                v.push_back(cnt);
            }
        }
    }
    
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    

    return 0;
}
