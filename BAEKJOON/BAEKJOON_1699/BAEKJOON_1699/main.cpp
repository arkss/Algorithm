#include <iostream>
#include <math.h>

using namespace std;

int dp[100002];

int min(int a, int b)
{
    return a<b ? a:b;
}

int main(int argc, const char * argv[]) {
    int N;
    
    int i,j;
    
    cin >> N;
    
    for(i=1;i<=N;i++){
        // 이 과정을 거치지 않으면 최소값이 0 이 되버린다.
        // 따라서 i번째의 경우, i값으로 초기화 해준다.
        dp[i] = i;
        // ex) 12라고 하면 12 이하의 제곱수들을 뺀 경우를 모두 고려해주자. 12-1**2, 12-2**2, 12-3**2 중에서 최소값을 찾아준다.
        for (j=1;j*j<=i;j++){
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }
    cout << dp[N] << endl;
}

