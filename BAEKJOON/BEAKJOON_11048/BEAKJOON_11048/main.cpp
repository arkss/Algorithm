#include <iostream>

int arr[1002][1002];

// 3개의 정수 중 최대값 return
int max(int a,int b,int c)
{
    int temp1 = a>b ? a:b;
    int temp2 = b>c ? b:c;
    return temp1>temp2 ? temp1:temp2;
}

int main(int argc, const char * argv[]) {
    int N,M;
    int i,j;
    
    std::cin >> N >> M;
    
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++){
            std::cin >> arr[i][j];
        }
    }
    // dp 적으로 전 3개 중 최대값을 현재꺼에 중첩해서 더해준다.
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++){
            arr[i][j] += max(arr[i-1][j],arr[i][j-1],arr[i-1][j-1]);
        }
    }
    std::cout << arr[N][M];
}
