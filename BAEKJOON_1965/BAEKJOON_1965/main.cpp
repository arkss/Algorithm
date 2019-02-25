#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];

int main(int argc, const char * argv[]) {
    int N;
    int i,j;
    int max=0;
    
    cin >> N;
    // 입력되는 배열 arr에 받고, dp 배열은 1로 초기화 해준다.
    for (i=1;i<=N;i++){
        cin >> arr[i];
        dp[i] = 1;
    }
    
    for(i=2;i<=N;i++){
        max = 0;
        for(j=1;j<i;j++){
            // 상자의 크기는 작고 && 가장 많이 담긴 상자를 찾아넣어준다.
            if (arr[i] > arr[j] && max < dp[j] )
                max = dp[j];
        }
        // 본인 상자까지 한 상자 추가 되었으므로 +1
        dp[i] = max+1;
    }
    
    max = 0;
    // 상자 중 가장 많이 담긴 상자를 찾아준다.
    for(i=0;i<=N;i++){
       if (max < dp[i])
           max = dp[i];
    }
    
    cout << max << endl;
}
