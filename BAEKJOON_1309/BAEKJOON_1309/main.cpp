#include <iostream>

using namespace std;

long long dp[100001][3];
/*
 i번째 행에 대해서
 dp[i][0] : i번째 줄에 사자가 아예 존재x
 dp[i][1] : i번째 줄에 사자가 왼쪽 존재
 dp[i][2] : i번째 줄에 사자가 오른쪽 존재
 
*/

int main(int argc, const char * argv[]) {
    int N;
    int i;
    long long answer;
    cin >> N;
    // N=1 일 때의 값은 수동으로 초기화
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for(i=2;i<=N;i++){
        // i번째에 사자가 없는 경우 = i-1번째의 모든 경우
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901;
        // i번째 사자가 왼쪽에 있는 경우 = i-1번째 사자 없는 경우 + i-1번째 사자가 오른쪽에 있는 경우
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901;
        // i번째 사자가 오른쪽에 있는 경우 = i-1번째 사자 없는 경우 + i-1번째 사자가 왼쪽에 있는 경우
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % 9901;
    }
    // 모든 경우를 다 합친 것이 원하는 경우의 수
    answer = (dp[N][0]+dp[N][1]+dp[N][2]) % 9901;

    cout << answer;
}
