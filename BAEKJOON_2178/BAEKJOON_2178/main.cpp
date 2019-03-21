#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int x;
    int y;
} element;

int maze[100][100];
// 해당 지점까지 도달하는데 얼마나 걸렸는지 확인하는 배열
int counts[100][100];

int N,M;


// 방향 이동을 위한 배열
int x_dir[4] = {0,0,1,-1};
int y_dir[4] = {1,-1,0,0};

void bfs(void)
{
    queue <element> q;
    element now = {0,0};
    q.push(now);
    // (0,0) 까지 이동 경로는 1
    counts[now.y][now.x] = 1;
    
    
    while (!q.empty()){
        now = q.front();
        q.pop();
        
        // 미로 탈출
        if (now.x == M-1 && now.y == N-1)
            break;
        
        for (int i=0;i<4;i++){
            element next;
            next.x = now.x + x_dir[i];
            next.y = now.y + y_dir[i];
            
            // 미로 범위를 벗어나면 continue
            if (next.x < 0 || next.x == M || next.y < 0 || next.y == N)
                continue;
            // 미로에 길이 있고, 이동한 적이 없으면 queue에 대입
            if (maze[next.y][next.x] && !counts[next.y][next.x]){
                counts[next.y][next.x] = counts[now.y][now.x] + 1;
                q.push(next);
            }
            
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    
    int i,j;
    cin >> N >> M;
    
    for(i=0;i<N;i++){
        char input[100];
        cin >> input;
        for(j=0;j<M;j++){
            
            maze[i][j] = input[j] - '0';
        }
    }
    
    bfs();

    cout << counts[N-1][M-1] << endl;
}

