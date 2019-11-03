#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define ROW 12
#define COL 6

char board[ROW][COL];
int visited[ROW][COL];

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

vector<pair<int,int>> v_total;
vector <pair<int,int>> v;

void dfs(int r, int c){
    v.push_back(make_pair(r,c));
    visited[r][c] = 1;
    char color = board[r][c];
    
    for (int i=0;i<4;i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0<=nr && nr<ROW && 0<=nc && nc<COL){
            if (board[nr][nc] == color && !visited[nr][nc]){
                dfs(nr, nc);
            }
        }
    }
}

int compare(pair<int,int> a, pair<int,int> b){
    if (a.second < b.second) return true;
    else if (a.second == b.second) {
        if (a.first < b.first) return true;
        else return false;
    }
    return false;
}

void delete_board(void){
    sort(v_total.begin(), v_total.end(), compare);
    for (int i=0;i<v_total.size();i++){
        for (int j=v_total[i].first;j>0;j--){
            board[j][v_total[i].second] = board[j-1][v_total[i].second];
        }
        board[0][v_total[i].second] = '.';
    }
}

int main(int argc, const char * argv[]) {
    
    for (int i=0;i<ROW;i++){
        string str;
        cin >> str;
        for (int j=0;j<COL;j++){
            board[i][j] = str[j];
        }
    }
    
    int answer = 0;
    
    while (1){
        v_total.clear();
        memset(visited, 0, sizeof(visited));
        for (int i=0;i<ROW;i++){
            for (int j=0;j<COL;j++){
                if (board[i][j] !='.' && !visited[i][j]){
                    v.clear();
                    dfs(i,j);
                    if (v.size() >= 4){
                        for (int i=0;i<v.size();i++){
                            v_total.push_back(v[i]);
                        }
                    }
                }
            }
        }
        if (v_total.empty()) break;
        answer++;
        delete_board();
        
    }
    
    cout << answer << "\n";
    return 0;
}
