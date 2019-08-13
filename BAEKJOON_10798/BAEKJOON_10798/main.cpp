#include <iostream>

using namespace std;

char board[5][15];

int main(int argc, const char * argv[]) {
    
    
    for (int i=0;i<5;i++){
        for (int j=0;j<15;j++){
            board[i][j] = '*';
        }
    }
    
    for (int i=0;i<5;i++){
        string line;
        cin >> line;
        
        for (int j=0;j<line.size();j++){
            board[i][j]=line[j];
        }
    }
    
    for (int j=0;j<15;j++){
        for (int i=0;i<5;i++){
            if (board[i][j] == '*') continue;
            cout << board[i][j];
        }
    }
    return 0;
}
