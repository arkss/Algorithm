#include <iostream>

int arr[1001]; // 입력되는 수들을 받는 배열
int dp[1001];  // 각 index에 해당하는 가장 긴 수열을 저장하는 배열

int main(int argc, const char * argv[]) {
    int num;
    int i,j;
    int max_num = 0;
    int result = 0; // 정답
    
    std::cin >> num;
    
    for(i=0;i<num;i++){
        std::cin >> arr[i];
    }
    
    dp[0] = 1; // 맨 앞을 기준으로 가장 긴 증가하는 수열은 무조건 1이다.
    for(i=1;i<num;i++){
        max_num = 0;
        // i 전 항들에 대해서 조사
        for (j=0;j<i;j++){
            // arr[i] 보다 작은 값을 가지는 애들 중에
            if (arr[i] > arr[j]){
                // dp[j]의 최대값을 max_num 에 저장
                if (max_num < dp[j]){
                    max_num = dp[j];
                }
            }
            // max_num 에서 한 칸 더 이동한다.
            dp[i] = max_num+1;
        }
    }
    // dp 중에서 가장 큰 값을 result에 넣고 출력
    for (i=0;i<num;i++){
        if (result < dp[i])
            result = dp[i];
    }
    std::cout << result;
    return 0;
}
