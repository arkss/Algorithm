#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[25][25];

int cnt = 0;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int y, int x, int N){
    cnt++;
    board[y][x] = 0;
    
    for (int i=0;i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        
        if (0<=ny && ny<N && 0<=nx && nx <N){
            if (board[ny][nx]){
                dfs(ny,nx,N);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            scanf("%1d", &board[i][j]);
        }
    }
    
    vector<int> v;
    
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (board[i][j]){
                cnt = 0;
                dfs(i,j,N);
                v.push_back(cnt);
            }
        }
    }
    
    sort(v.begin(), v.end());
    
    cout << v.size() << "\n";
    for (int i=0;i<v.size();i++){
        cout << v[i] << "\n";
    }

    return 0;
}
