#include <iostream>

int max(int a, int b)
{
    return a>b ? a:b;
}
int main(int argc, const char * argv[]) {
    int num; // 몇 개의 숫자가 들어오는지 결정해주는 변수
    int i,j;
    int result = 0; // 최종적인 최대값을 저장할 변수
    int temp = 0;
   
    
    std::cin >> num;
    
    int arr[num]; // 입력 수들을 저장할 배열
    int dp[num]; // 각 index 마다 해당 index에서 시작했을 때의 최대값을 저장
    
    // temp[num] 0으로 초기화.
    for (i=0;i<num;i++){
        dp[i] = 0;
    }
    
    // 값입력
    for (i=0;i<num;i++){
        std::cin >> arr[i];
    }
    
//
//    dp[0] = max(dp[0], arr[0]);
//    dp[0] = max(dp[0], arr[0] + arr[1]);
//    dp[0] = max(dp[0], arr[0]+arr[1]+arr[2]);
    
    for (i=0;i<num;i++){
        temp = 0;
        for (j=i;j<num;j++){
            temp += arr[j];
            dp[i] = max(dp[i],temp);
        }
    }
    
    for (i=0;i<num;i++){
        if (dp[i] > result)
            result = dp[i];
    }

    std::cout << result << std::endl;
    
//    for (i=0;i<num;i++){
//        std::cout << dp[i] << std::endl;
//    }
    
}
