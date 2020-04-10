#include <iostream>
#include <vector>

using namespace std;

int board[12][12];
int answer;

bool queen_check(int x,int y,int n){
    // 위쪽 확인
    for (int i=0;i<x;i++){
        if (board[i][y]) return false;
    }

    // 왼대각확인
    int tempX = x;
    int tempY = y;
    while (1){
        tempX--; tempY--;
        if (tempX < 0 || tempX >= n) break;
        if (tempY < 0 || tempY >= n) break;
        if (board[tempX][tempY]) return false;
    }

    // 오른대각확인
    tempX = x;
    tempY = y;
    while (1){
        tempX--; tempY++;
        if (tempX < 0 || tempX >= n) break;
        if (tempY < 0 || tempY >= n) break;
        if (board[tempX][tempY]) return false;
    }

    return true;
}

void print_board(int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

void backtracking(int n, int row){
    if (n == row) {
        // print_board(n);
        // cout << "\n";
        answer++;
        return;
    }
    
    for (int i=0;i<n;i++){
        if (queen_check(row, i, n)){
            board[row][i] = 1;
            backtracking(n, row+1);
            board[row][i] = 0;
        }
    }
}

int solution(int n){
    answer = 0;
    backtracking(n, 0);
    return answer;
}

int main(){
    cout << solution(4) << "\n";
    return 0;
}