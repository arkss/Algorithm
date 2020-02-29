#include <iostream>

using namespace std;

int answer = 0; // 정답 변수
int N;

// 있으면 1 없으면 0
int check_col[15];
int check_left[30];
int check_right[30];

int dfs(int now_row)
{
    int i;
    // 체스판의 크기 만큼 탐색을 했으면 경우의 수를 하나 늘려준다.

    if (now_row == N){
        answer++;
        return 0;
    }
    else{
        for(i=0;i<N;i++){
            // 위쪽이나 대각선에 이미 퀸이 있으면 다음 구역을 확인한다.
            if(check_col[i] || check_left[N-(i-now_row+1)] || check_right[now_row+i])
                continue;
            // 퀸이 들어갔음을 추가해준다.
            check_col[i] = 1;
            check_left[N-(i-now_row+1)] = 1;
            check_right[now_row+i] = 1;
            // dfs 로 다음 위치를 탐색한다.
            dfs(now_row+1);
            // 다음 과정을 위해서 다시 퀸을 없애준다.
            check_col[i] = 0;
            check_left[N-(i-now_row+1)] = 0;
            check_right[now_row+i] = 0;

        }
    }

    return 0;
}
int main(int argc, const char * argv[]) {

    cin >> N;

    dfs(0);

    cout << answer;

    return 0;
}
