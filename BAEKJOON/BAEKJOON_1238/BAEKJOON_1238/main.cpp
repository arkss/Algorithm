#include <iostream>

#define INF 1000000
using namespace std;

int A[1005][1005];
int student[1005];

int main(int argc, const char * argv[]) {
    int N,M,X;
    int i,j,k;
    cin >> N >> M >> X;
    
    // 입력 값으로 배열 초기화
    for (i=0;i<M;i++){
        int start_node, end_node, weight;
        cin >> start_node >> end_node >> weight;
        A[start_node][end_node] = weight;
    }
    // 대각성분은 그대로 0, 대각성분이 아니면서 0인 부분은 큰 값 INF를 대입
    for (i=1;i<=N;i++){
        for (j=1;j<=N;j++){
            if (i==j)
                continue;
            if (!A[i][j])
                A[i][j] = INF;
        }
    }
    
    for (k=1;k<=N;k++){
        for(i=1;i<=N;i++){
            for(j=1;j<=N;j++){
                if (A[i][k] + A[k][j] < A[i][j])
                    A[i][j] = A[i][k] + A[k][j];
            }
        }
    }

    int max = 0;
    for (i=1;i<=N;i++){
        student[i] = A[i][X] + A[X][i];
        if (student[i] > max)
            max = student[i];
    }

    cout << max;

    

}
