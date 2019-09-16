#include <iostream>
#include <algorithm>

using namespace std;

int board[1000][1000];

void append(string &s, char c, int cnt){
    for (int i=0;i<cnt;i++){
        s+= c;
    }
}

int main(int argc, const char * argv[]) {
    
    int row,col;
    cin >> row >> col;
    
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            cin >> board[i][j];
        }
    }
    string answer = "";
    
    // row 가 홀수인 경우
    if (row%2==1){
        // 0: 오른쪽, 1: 왼쪽
        int dir = 1;
        for (int i=0;i<row;i++){
            dir = 1-dir;
            for (int j=0;j<col-1;j++){
                if (dir) answer+="L";
                else answer+="R";
            }
            if (i!=row-1) answer+="D";
        }
    }
    // col 이 홀수인 경우
    else if (col%2 == 1) {
        // 0: 아래쪽, 1:위쪽
        int dir = 1;
        for (int i=0; i<col; i++) {
            dir = 1-dir;
            for (int j=0;j<row-1;j++){
                if (dir) answer+="U";
                else answer+="D";
            }
            if (i!=col-1) answer+="R";
        }
    }

    // row, col 이 둘 다 짝수인 경우
    else {
        // 지나지 말아야 할 점 찾기
        int x,y;
        x=0;
        y=1;
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if ((i+j)%2==1 && board[x][y] > board[i][j]){
                    x = i;
                    y = j;
                }
            }
        }
        
        int x1=0;
        int y1=0;
        int x2=row-1;
        int y2=col-1;
        string subAnswer = "";
        while (x2-x1>1){
            if (x1/2 < x/2) {
                append(answer, 'R', col-1);
                append(answer, 'D', 1);
                append(answer, 'L', col-1);
                append(answer, 'D', 1);
                x1 += 2;
            }
            if (x/2 < x2/2) {
                append(subAnswer, 'R', col-1);
                append(subAnswer, 'D', 1);
                append(subAnswer, 'L', col-1);
                append(subAnswer, 'D', 1);
                x2 -= 2;
            }
        }
        while (y2-y1>1){
            if (y1/2 < y/2) {
                append(answer, 'D', 1);
                append(answer, 'R', 1);
                append(answer, 'U', 1);
                append(answer, 'R', 1);
                y1 += 2;
            }
            if (y/2 < y2/2) {
                append(subAnswer, 'D', 1);
                append(subAnswer, 'R', 1);
                append(subAnswer, 'U', 1);
                append(subAnswer, 'R', 1);
                y2 -= 2;
            }
        }
        if (y == y1) {
            append(answer, 'R', 1);
            append(answer, 'D', 1);
        } else {
            append(answer, 'D', 1);
            append(answer, 'R', 1);
        }
        reverse(subAnswer.begin(), subAnswer.end());
        answer += subAnswer;
    }
    
    
    
    
    cout << answer << "\n";
    
    return 0;
}
