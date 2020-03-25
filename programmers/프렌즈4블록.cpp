#include <iostream>
#include <vector>

using namespace std;

bool check[31][31];

void clear_check(int m,int n){
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            check[i][j] = 0;
        }
    }
}

void print_board(int m, int n, vector<string> board){
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int solution(int m, int n, vector<string> board){
    int answer = 0;
    while (1){
        //print_board(m,n,board);
        int flag = 1;
        for (int i=0;i<m-1;i++){
            for (int j=0;j<n-1;j++){
                char temp = board[i][j];
                if (temp!= '-' && temp == board[i+1][j] && temp == board[i][j+1] && temp == board[i+1][j+1]){
                    flag = 0;
                    if (!check[i][j]) {
                        check[i][j] = 1;
                        answer++;
                    }
                    if (!check[i+1][j]){
                        check[i+1][j] = 1;
                        answer++;
                    }
                    if (!check[i][j+1]) {
                        check[i][j+1] = 1;
                        answer++;
                    }
                    if (!check[i+1][j+1]) {
                        check[i+1][j+1] = 1;
                        answer++;
                    }
                }
            }
        }

        if (flag) break;

        cout << "change_board\n";
        // change_board
        for (int i=0;i<m;i++){
           for (int j=0;j<n;j++){
                if (check[i][j] == 1) board[i][j] = '-';
            }
        }

        // move_board
        for (int j=0;j<n;j++){
            for (int i=m-1;i>=0;i--){        
                if (board[i][j] == '-'){
                    for (int k=i-1;k>=0;k--){
                        if (board[k][j] != '-'){
                            board[i][j] = board[k][j];
                            board[k][j] = '-';
                            break;
                        }
                    }
                }
            }
        }
        clear_check(m, n);
    }
    
    
    return answer;
}

int main(){
    cout << solution(6,6, {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"});
    return 0;
}