#include <iostream>

using namespace std;

int n,m;
int board[500][500][2];
// board[i][j][1] 에는 지나갔던 경로인지 아닌지를 체크한다.
// 처음 가는 경로면 0, 가본 경로면 1


int dfs(int i,int j, int size)
{
    board[i][j][1] = 1; // 방문으로 표시
//    cout << "dfs 실행" << size << endl;
    
    if (i>0 && board[i-1][j][1] == 0 && board[i-1][j][0] == 1){
        size++;
        size = dfs(i-1,j,size);
    }
    
    if (i<n-1 && board[i+1][j][1] == 0 && board[i+1][j][0] == 1){
        size++;
        size = dfs(i+1,j,size);
    }
    
    if (j>0 && board[i][j-1][1] == 0 && board[i][j-1][0] == 1){
        size++;
        size = dfs(i,j-1,size);
    }
    
    if (j<m-1 && board[i][j+1][1] == 0 && board[i][j+1][0] == 1){
        size++;
        size = dfs(i,j+1,size);
    }
    
    return size;
    
}
int main(int argc, const char * argv[]) {
    
    
    cin >> n >> m;
    
    int i,j;
    
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> board[i][j][0];
        }
    }
    
    int max_size = 0; // 그림의 최대넓이
    int count = 0; // 그림의 수
    
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if (board[i][j][0] == 1 && board[i][j][1] == 0){
                int size = 1;
                size = dfs(i,j, size);
               
                if (size > max_size)
                    max_size = size;
                count++;
            }
        }
    }
    
    cout << count << endl << max_size;
    
}
