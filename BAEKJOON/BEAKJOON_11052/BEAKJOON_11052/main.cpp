#include <iostream>

// 두 수 중 최대값 반환
int max(int a, int b)
{
    return a>b ? a:b;
}
int card[1001]; // n장짜리 카드팩의 비용은 card[n]
int dp[1001];   // n장의 카드를 사는데 드는 최대비용은 dp[n]

int main(int argc, const char * argv[]) {
    int num; // 몇 개의 card를 뽑아야하는지
    int i,j;
    
    std::cin >> num;
    
    for(i=1;i<=num;i++){
        std:: cin >> card[i];
    }
    
    // 카드를 n개 샀을 때의 최대값 = max(n-i개 샀을 떄의 최대값에 i개 더 산 것)
    for(i=1;i<=num;i++){
        for (j=1;j<=i;j++){
            dp[i] = max(dp[i], dp[i-j] + card[j]);
        }

        
    }
    
    std::cout << dp[num] << std::endl;
    
    
}
