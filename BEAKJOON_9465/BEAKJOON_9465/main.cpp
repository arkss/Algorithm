
#include <iostream>

int arr[2][1000002];
int dp[2][1000002];

int max(int a,int b)
{
    return a>b ? a:b;
}
int main(int argc, const char * argv[]) {
    int T;
    int i,j;
    
    std::cin >> T;
    
    
    
    for (int k=0;k<T;k++){
        int n;
        std::cin >> n;
        // arr 배열에 값 채우기, dp도 똑같이 채움
        for (j=0;j<2;j++){
            for (i=1;i<=n;i++){
                std::cin >> arr[j][i];
                dp[j][i] = arr[j][i];
            }
        }
        // dp적으로 앞의 정보들을 이용해서 현재 위치까지의 최대 지불 금액을 계산
        // 입구자와 날일자 방향에 있는 값들 중 최대값을 선택.
        for (i=2;i<=n;i++){
            dp[0][i] += max(dp[1][i-1],dp[1][i-2]);
            dp[1][i] += max(dp[0][i-1],dp[0][i-2]);
        }

        
        std::cout << max(dp[0][n],dp[1][n]) << std::endl;
    }
    
    
    
}
