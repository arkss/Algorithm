#include <iostream>

using namespace std;

int w,h; // 가로,세로 길이
// 8개 경우에 대해서 하나씩 다 해줘야 하나?
// 반복문으로 합칠 수 있을 것 같은데 겹치는 부분을 못찾겠다.
int checking(int (*grid)[51],int i,int j)
{
    int check = grid[i][j];
    grid[i][j] = 2;
    // 위쪽 탐색
    if (i>0){
        if(check == grid[i-1][j])
            checking(grid,i-1,j);
    }
    // 아래쪽 탐색
    if (i<h-1){
        if(check == grid[i+1][j])
            checking(grid,i+1,j);
    }
    // 왼쪽 탐색
    if (j>0){
        if(check == grid[i][j-1])
            checking(grid,i,j-1);
    }
    // 오른쪽 탐색
    if (j<w-1){
        if (check == grid[i][j+1])
            checking(grid,i,j+1);
    }
    // 좌상대각
    if (i>0 && j>0){
        if (check == grid[i-1][j-1])
            checking(grid,i-1,j-1);
    }
    // 우상대각
    if (i>0 && j<w-1){
        if (check == grid[i-1][j+1])
            checking(grid,i-1,j+1);
    }
    // 좌하대각
    if (i<h-1 && j>0){
        if (check == grid[i+1][j-1])
            checking(grid,i+1,j-1);
    }
    // 우하대각
    if (i<h-1 && j<w-1){
        if (check == grid[i+1][j+1])
            checking(grid,i+1,j+1);
    }
    
    
    return 0;
}
int main(int argc, const char * argv[]) {
    
    int i,j;
    int count = 0;
    
    int grid[51][51]; // 1:땅, 0:바다, 2:가본곳
    
    while (1){
        count = 0;
        cin >> w >> h;
        // 0 0 들어오면 끝
        if (w==0 && h==0)
            break;
        
        // 지도 값 받기
        for (i=0;i<h;i++){
            for (j=0;j<w;j++){
                cin >> grid[i][j];
            }
        }
        // 모든 경로를 순회하며
        for (i=0;i<h;i++){
            for (j=0;j<w;j++){
                // 땅이면 땅의 수를 하나 올리고 주변 지역 순회
                if (grid[i][j] == 1){
                    count++;
                    checking(grid,i,j);
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
