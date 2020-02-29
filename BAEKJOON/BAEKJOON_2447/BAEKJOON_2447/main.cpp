#include <iostream>

using namespace std;

char board[2188][2188];

void solve(int y,int x,int N){
    
    if (N==1){
        board[y][x] = '*';
        return;
    }
    
    
    int M = N/3;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (i==1 && j==1) continue;
            solve(y+i*M,x+j*M,M);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            board[i][j] = ' ';
        }
    }
    
    solve(0,0,N);
    
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cout << board[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}
