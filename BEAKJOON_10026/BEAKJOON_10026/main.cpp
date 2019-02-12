#include <iostream>

using namespace std;

int N;

// 이거 함수 매개변수 받을 때 **grid 처럼 2중포인터로 받으면 왜안되는거지???
int checking(char (*grid)[101],int (*check)[101], int i, int j)
{
    // 가본 지역이라고 표시
    check[i][j] = 1;
    // 위쪽 탐색
    if (i>0){
        // 위쪽 지역이 안가본 지역이고 같은 지역이면 이동
        if (check[i-1][j] == 0 && grid[i][j] == grid[i-1][j])
            checking(grid, check, i-1,j);
    }
    // 아래쪽 탐색
    if (i<N-1){
        if (check[i+1][j] == 0 && grid[i][j] == grid[i+1][j])
            checking(grid, check, i+1,j);
    }
    // 왼쪽 탐색
    if (j>0){
        if (check[i][j-1] == 0 && grid[i][j] == grid[i][j-1])
            checking(grid, check, i,j-1);
    }
    // 오른쪽 탐색
    if (j<N-1){
        if (check[i][j+1] == 0 && grid[i][j] == grid[i][j+1])
            checking(grid, check, i,j+1);
    }
    return 0;
}

int main(){
    
    char grid[101][101]; // 적록색약이 아닌 사람이 본 구역
    char grid2[101][101]; // 적록색약인 사람이 본 구역
    
    int check[101][101]={0}; // grid 에 대해서 가본 지역 표시
    int check2[101][101]={0};// grid2에 대해서 가본 지역 표시
    // 1 : 가본 지역, 0: 안가본 지역
    
    int i,j;
    int count1 = 0; // 적록색약이 아닌 사람이 봤을 때 구역 수
    int count2 = 0; // 적록색약인 사람이 봤을 때 구역 수
    
    cin >> N;
    
    // 값 입력받아 그리드 완성
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            cin >> grid[i][j];
            //grid2 는 G를 R로 바꿔준다.
            if (grid[i][j] == 'G')
                grid2[i][j] = 'R';
            else
                grid2[i][j] = grid[i][j];
        }
    }
    
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            // 안가본 지역이면
            if (check[i][j] == 0){
                // 지역의 수 증가하고
                count1++;
                // 탐색
                checking(grid, check, i,j);
            }
            if (check2[i][j] == 0){
                count2++;
                checking(grid2, check2, i,j);
            }
        }
    }
    
    cout << count1 << " " << count2;
    
}
