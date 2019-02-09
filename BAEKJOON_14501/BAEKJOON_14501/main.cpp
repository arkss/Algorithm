#include <iostream>

int arr[2][16]; // 입력되는 값을 받는 배열, index와 날짜를 맞춰주기 위해서 1번째 열은 비워놓자.
int dp[2][16];

int main(int argc, const char * argv[]) {
    int N;
    int i,j;
    int max = 0;
    int result = 0;

    
    std::cin >> N;
    
    // 배열에 값 받기
    for (i=1;i<=N;i++){
        for (j=0;j<2;j++){
            std::cin >> arr[j][i];
            dp[j][i] = arr[j][i];
        }
    }
    
    // dp 계산
    // (구하고자 하는 날짜 - 과거의 날짜) > 과거 날짜 상담일수 인 경우에 상담이 가능하다. 이런 경우의 금액의 최대값을 구해서 구하고자 하는 날짜의 금액에 더해준다.
    for (i=2;i<=N;i++){
        for (j=1;j<i;j++){
            if ((i-j >= arr[0][j]) && (max < dp[1][j])){
                max = dp[1][j];
            }
        }
        dp[1][i] += max;
    }
    
    // 최대값 찾기
    // 구한 dp 값들 중에서 최대값을 찾아준다.
    // 단 주의해야할 사항은 최대값 중에서
    // 날짜 + 해당날짜업무의 소요일수가 N+1 이하인 날만 상담할 수 있으므로 그런 경우만 고려해준다.
    for (i=1;i<=N;i++){
        if ((dp[1][i] > result) && i+arr[0][i] <= N+1)
            result = dp[1][i];
    }
// dp 배열 확인
//    for (j=0;j<2;j++){
//        for (i=1;i<=N;i++){
//            std::cout.width(3);
//            std::cout << dp[j][i];
//        }
//        std::cout << std::endl;
//    }
    
    std::cout << result << std::endl;
}

