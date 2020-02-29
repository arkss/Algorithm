#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main(int argc, const char * argv[]) {

    char board[12][12];
    vector <pair<int,int>> arr;
    
    

    for (int i=0;i<12;i++){
        for (int j=0;j<12;j++){
            board[i][j] = '.';
        }
    }

    int row, col;
    cin >> row >> col;

    for (int r=1;r<=row;r++){
        for (int c=1;c<=col;c++){
            cin >> board[r][c];
        }
    }
    
    for (int r=1;r<=row;r++){
        for (int c=1;c<=col;c++){
            if (board[r][c] == 'X'){
                int count = 0;
                for (int i=0;i<4;i++){
                    int new_r = r + dx[i];
                    int new_c = c + dy[i];
                    if (board[new_r][new_c] == '.'){
                        count++;
                    }
                }
                // 바로 바꾸면 바뀐 값이 다른 지역에 영향을 미치므로 O 로 체크를 해놓고 마지막에
                if (count >= 3) {
                    arr.push_back(make_pair(r,c));
                }
            }
            
        }
    }
    
    for (int i=0;i<arr.size();i++){
        board[arr[i].first][arr[i].second] = '.';
    }
    
    int min_row=11, max_row=0, min_col=11, max_col=0;
    for (int r=1;r<=row;r++){
        for (int c=1;c<=col;c++){
            if (board[r][c] == 'X'){
                min_row = min(min_row, r);
                max_row = max(max_row, r);
                min_col = min(min_col, c);
                max_col = max(max_col, c);
            }
        }
    }
//
    for (int r=min_row;r<=max_row;r++){
        for (int c=min_col;c<=max_col;c++){
            cout << board[r][c];
        }
        cout << "\n";
    }
    return 0;
}
