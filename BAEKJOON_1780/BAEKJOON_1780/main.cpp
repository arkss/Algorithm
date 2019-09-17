#include <iostream>

using namespace std;

int board[2187][2187];

// index 0 : -1 개수, index 1 : 0 개수, index 2 : 1개수
int countNum[3];
int N;

int same(int y,int x,int N){
    int temp = board[y][x];
    for (int i=y;i<y+N;i++){
        for (int j=x;j<x+N;j++){
            if (temp != board[i][j])
                return 0;
        }
    }
    return 1;
}

void check(int y,int x,int N){
    
    if (same(y,x,N)){
        countNum[board[y][x]+1] ++;
        return;
    }
    
    int M = N/3;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            check(y+M*i,x+M*j,M);
        }
    }
    
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> board[i][j];
        }
    }
    
    check(0,0,N);
    
    for (int i=0;i<3;i++){
        cout << countNum[i] << "\n";
    }
    return 0;
}
