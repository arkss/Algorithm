#include <iostream>

int max(int a, int b)
{
    return a>b ? a:b;
}
int main(int argc, const char * argv[]) {
    int num; // 몇 개의 숫자가 들어오는지 결정해주는 변수
    int i;
    int result = 0; // 최종적인 최대값을 저장할 변수
   
    
    std::cin >> num;
    
    int arr[num+1]; // 입력 수들을 저장할 배열
    int dp[num+1]; // 각 index 마다 해당 index까지의 최대값을 저장
    
    // 값입력
    for (i=0;i<num;i++){
        std::cin >> arr[i];
    }
    
    
    // 전 항까지의 최대값과 현재 항의 값을 비교하며 최대값을 취한다.
    dp[0] = arr[0];
    for (i=0;i<num;i++){
        dp[i+1] = max(dp[i]+arr[i+1],arr[i+1]);
    }
    
    // dp 배열은 각 index까지의 최대값이 담겨있으므로 이를 비교해서 최대값을 result에 저장
    result = dp[0];
    for (i=1;i<num;i++){
        if (result < dp[i])
            result = dp[i];
    }

    // 값 출력
    std::cout << result << std::endl;
}
