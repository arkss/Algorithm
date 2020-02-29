#include <iostream>

using namespace std;

int arr[1000][1000];
int visited[1000][1000];
int M,N;
int x_dir[4] = {0,0,1,-1};
int y_dir[4] = {1,-1,0,0};
int flag;

void printArr(){
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            cout << visited[i][j];
        }
        cout << endl;
        
    }
    cout << endl;

}

void dfs(int x, int y){
    
    for (int i=0;i<4;i++){
        if (flag)
            return;
        int next_x = x + x_dir[i];
        int next_y = y + y_dir[i];
        // 유효한 범위 안에 있고
        if (next_x >= 0 && next_x < M && next_y >=0 && next_y < N){
            // 전류가 지나갈 수 있는 상태면
            if (!arr[next_x][next_y] && !visited[next_x][next_y]){
                visited[next_x][next_y] = 1;
                // 제일 꼭대기까지 올라왔으면
                if (!next_x) flag=1;
//                printArr();
                dfs(next_x, next_y);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> M >> N;

    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    
    for(int i=0;i<N;i++){
        if (!arr[M][i] && !visited[M][i]){
            visited[M][i] = 1;
            dfs(M,i);
        }
    }
   
    if(flag) cout << "YES";
    else cout << "NO";
    
    return 0;
    
}


/*
 
 2차원 M*N 격자
 위쪽이 바깥쪽, 아래쪽을 안쪽
 
 검은색은 전류 x -> 1
 흰색은 전류 o -> 0
 
 바깥쪽에서 전기가 들어온다.
 
 
  M (2 ≤ M ≤ 1,000) ,N (2 ≤ N ≤ 1,000)
 
 
 */
