#include <iostream>
#include <queue>

using namespace std;

int arr[1001][1001]; // 창고를 의미하는 배열

typedef struct {
    int y;
    int x;
} Location;

int main(int argc, const char * argv[]) {
    int M,N; // 가로 폭, 세로 폭
    
    cin >> M >> N;
    
    int i, j;
    int result = 0;
    
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    
    // 창고 배열 초기화
    for (i=0;i<N;i++){
        for(j=0;j<M;j++){
            cin >> arr[i][j];
            
        }
    }
    
    queue<Location>q;
    
    for (i=0;i<N;i++){
        for (j=0;j<M;j++){
            if (arr[i][j] == 1)
                q.push({i,j});
        }
    }
    int count = 0;
    Location loc;
    int x,y;
    while (1){
        
        // 큐가 비어있으면 중지
        if (q.size() == 0)
            break;
        unsigned long length = q.size();
        
//        cout << "#"<< endl;
//        cout << length<< endl;
        // 큐의 길이 만큼 반복
        for (i=0;i<length;i++){
            // 큐 제일 앞 원소 반환 및 삭제
            loc = q.front();
            q.pop();
            
            // 위치를 받아와서
            y = loc.y;
            x = loc.x;
            
//            cout << y << "," << x << endl;
            
            // 위 아래 좌 우 를 전부 살펴서
            for(j=0;j<4;j++){
                int after_y = y + dy[j];
                int after_x = x + dx[j];
                // 배열 밖으로 벗어나면 다시
                if (after_y < 0 || after_y >= N || after_x < 0 || after_x >= M ){
                    continue;
                }
                // -1이면 다시
                if (arr[after_y][after_x] == -1)
                    continue;
                // 1이어도 다시
                if (arr[after_y][after_x] == 1)
                    continue;
                
//                cout << after_y << "," << after_x << endl;
                // 1로 값을 바꿔주고 큐에 넣어준다.
                arr[after_y][after_x] = 1;
                q.push({after_y, after_x});
            }
    }
        count++;
    }
    
    for(i=0;i<N;i++){
        bool flag = false;
        for(j=0;j<M;j++){
            if (arr[i][j] == 0){
//                cout << i << "," << j << endl;
                result = -1;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    
    if (result == -1)
        cout << result;
    else
        cout << count-1;
    
//    for (i=0;i<N;i++){
//        for(j=0;j<M;j++){
//
//            cout.width(2);
//            cout << ind[i][j];
//        }
//        cout << endl;
//    }
    
}
