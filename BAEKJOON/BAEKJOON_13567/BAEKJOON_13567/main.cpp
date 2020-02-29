#include <iostream>

using namespace std;

int x_pos, y_pos, dir;
// dir 0: 오른쪽 , 1: 위 , 2: 왼쪽, 3: 아래

int checkValid(int M){
    if (x_pos < 0 || x_pos > M || y_pos < 0 || y_pos > M){
        return 0;
    }
    return 1;
}

void action(){
    char act[4];
    int d;
    cin >> act >> d;
    if (act[0] == 'M'){
        if (dir == 0){
            x_pos+=d;
        }
        else if (dir == 1){
            y_pos+=d;
        }
        else if (dir == 2){
            x_pos-=d;
        }
        else{
            y_pos-=d;
        }
    }
    
    else{
        if (d==0){
            dir++;
        }
        else{
            dir--;
        }
        dir+=4;
        dir%=4;
    }
}

int main(int argc, const char * argv[]) {
    int M,n;
    
    cin >> M >> n;
    
    for (int i=0;i<n;i++){
        action();
        int valid = checkValid(M);
        if (!valid){
            cout << -1 << endl;
            return 0;
        }
        
    }
    cout << x_pos << " "<< y_pos;
    return 0;
}


/*
 왼쪽아래 꼭지점은 (0,0)
 오른쪽 위 꼭지점은 (M,M)
 
 처음엔 동쪽 방향
 
 TURN
 0 : 왼쪽으로 90도 회전
 1 : 오른쪽으로 90도 회전
 MOVE
 x : x 만큼 앞으로 이동
 
[ 입력 ]
 M,n (1 ≤ M ≤ 1,000, 1 ≤ n ≤ 1,000)
 
 M은 지도의 크기, n은 명령의 개수
 
 [ 출력 ]
 로봇의 위치 x,y
 유효하지 않은 위치면 -1
 
 
 
 */
