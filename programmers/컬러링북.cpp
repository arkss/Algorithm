#include <iostream>
#include <vector>

using namespace std;

bool visited[101][101];

int M,N;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int size_of_one_area;

void DFS(int x,int y, vector<vector<int>> picture) {
    //cout << x << " " << y << " 에서의 DFS시작\n";
    visited[x][y] = 1;
    size_of_one_area++;
    
    for (int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 > nx || nx > M-1 || 0 > ny || ny > N-1) continue;
        if (picture[nx][ny] == picture[x][y]){
            if (!visited[nx][ny])
                DFS(nx, ny, picture);
        }   
    }
}

void clear_visited(int m,int n){
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            visited[i][j] = 0;
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    M = m, N = n;
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    clear_visited(m,n);

    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            size_of_one_area = 0;
            if (!visited[i][j] && picture[i][j] != 0){
                DFS(i, j, picture);
                number_of_area++;
            }
            if (max_size_of_one_area < size_of_one_area) max_size_of_one_area = size_of_one_area;
        }
    }

    cout << number_of_area << " " << max_size_of_one_area << "\n";
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main(){
    solution(5, 4, {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}});
}

// {
//     {1, 1, 1, 0},
//     {1, 2, 2, 0},
//     {1, 0, 0, 1},
//     {0, 0, 0, 1}, 
//     {0, 0, 0, 3},
//     {0, 0, 0, 3}
// }








