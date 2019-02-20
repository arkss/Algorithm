
#include <iostream>

using namespace std;

int coin[102];
int dp[100002];

int main(int argc, const char * argv[]) {
    int n,k; // 동전의 종류, 계산해야할 값
    int i,j;
    
    
    std::cin >> n >> k;
    
    // 입력되는 코인을 coin 배열에 저장
    for(i=1;i<=n;i++){
        std::cin >> coin[i];
    }
    // dp[i][k] 는 i번째 동전까지 사용하여 k를 만들 수 있는 경우의 수
    
    for (i=1;i<=n;i++){
        dp[0] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            // 동전의 가치보다 더 큰 금액을 만드려고 하면
            // 이 동전을 안쓰고 만든 경우의 수 + 이 동전을 사용하여 만드는 경우의 수
            if (j >= coin[i]) {
                dp[j] +=  dp[j - coin[i]];
            }
            // (j < coin[i])
            // 만드는 금액이 동전의 가치보다 작다면 i번째 동전을 사용하던 사용안하던 같은 금액이다.
            
        }
    }
    cout << dp[k];
}

