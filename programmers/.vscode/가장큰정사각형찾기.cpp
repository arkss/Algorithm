#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int> > board)
{

    for (int i=board.size()-2;i>=0;i--){
        for (int j=board[0].size()-2;j>=0;j--){
            if (board[i][j]){
                board[i][j] = min(board[i+1][j+1], min(board[i+1][j], board[i][j+1]))+1;
            }
        }
    }

    int maxSize = 1;
    // 1이면 전부 다 0만
    int zeroFlag = 1;

    for (int i=0;i<board.size();i++){
        for (int j=0;j<board[0].size();j++){
            if (zeroFlag && board[i][j] == 1){
                zeroFlag = 0;
            }
            //cout << board[i][j] << " ";
            if (maxSize < board[i][j]){
                maxSize = board[i][j];
            }
        }
        //cout << "\n";
    }
    if (zeroFlag) return 0;
    int answer = maxSize * maxSize;
    return answer;
}

int main(){
    int boardArr[1001][1001] = {
        {0,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {0,0,1,0}
    };
    vector<vector<int> > board;
    vector<int> row1(boardArr[0], boardArr[0]+4);
    vector<int> row2(boardArr[1], boardArr[1]+4);
    vector<int> row3(boardArr[2], boardArr[2]+4);
    vector<int> row4(boardArr[3], boardArr[3]+4);
    board.push_back(row1);
    board.push_back(row2);
    board.push_back(row3);
    board.push_back(row4);
    cout << solution(board) << "\n";
}