#include <iostream>

using namespace std;

char board[9][9];
int main(int argc, const char * argv[]) {
    
    int i,j;
    // 체스판 채우기
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            cin >> board[i][j];
        }
    }
    // 말의 개수
    int count = 0;
    
    // 하얀칸만 탐색
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if (board[i][j] == 'F' && (i+j) % 2 == 0)
                count++;
        }
    }
    
    cout << count;
//    for(i=0;i<8;i++){
//        for(j=0;j<8;j++){
//            cout << board[i][j];
//        }
//        cout << endl;
//    }
//

}
