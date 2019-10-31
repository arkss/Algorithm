#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

char board[31][31][31];
int test[31][31][31];

int dh[] = {0,0,0,0,1,-1};
int dr[] = {0,0,1,-1,0,0};
int dc[] = {1,-1,0,0,0,0};

typedef struct pair3 {
    int h;
    int r;
    int c;
} pair3;

int bfs(pair3 start,int height, int rows, int cols){
    queue<pair3> q;
    q.push(start);
    
    int distance = 0;
    
    while(!q.empty()){
        int q_size = q.size();
        for (int i=0;i<q_size;i++){
            //cout << i << "\n";
            int h = q.front().h;
            int r = q.front().r;
            int c = q.front().c;
            q.pop();
            
            for (int i=0;i<6;i++){
                int nh = h + dh[i];
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (0<=nh && nh<height && 0<=nr && nr<rows && 0<=nc && nc<cols){
                    
                    if(board[nh][nr][nc] == 'E'){
                        return distance;
                    }
                    
                    else if (board[nh][nr][nc] == '.'){
                        board[nh][nr][nc] = '#';
                        test[nh][nr][nc] = distance;
                        pair3 npoint = {nh,nr,nc};
                        q.push(npoint);
                    }
                }
            }
        }
        distance++;
        
        
        
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    
    
    while (1){
        memset(board, 0, sizeof(board));
        
        int height, rows, cols;
        cin >> height >> rows >> cols;
        
        if (height == 0 && rows == 0 && cols == 0)
            return 0;
        
        pair3 start;
        
        for (int h=0;h<height;h++){
            for (int r=0;r<rows;r++){
                string str;
                cin >> str;
                for (int c=0;c<cols;c++){
                    board[h][r][c] = str[c];
                    test[h][r][c] = str[c];
                    if (board[h][r][c] == 'S'){
                        start = {h,r,c};
                    }
                }
            }
        }
        
        int result = bfs(start,height, rows, cols);
        
        if (result == -1)
            cout << "Trapped!" << "\n";
        else
            cout << "Escaped in " << result+1 << " minute(s)." << "\n";
        
    }
    return 0;
}
