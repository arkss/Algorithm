#include <iostream>

using namespace std;

int arr[10000];
int dp[10000];

int max(int a,int b)
{
    return a>b ? a:b;
}

int main(int argc, const char * argv[]) {
    int N;
    int i;
    
    cin >> N;
    
    for(i=1;i<=N;i++){
        cin >> arr[i];
    }
    
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    
    for(i=3;i<=N;i++){
        // i번째 와인을 마신 경우, i-1번째 와인을 마신 경우와 마시지 않은 경우를 비교해준다.
        dp[i] = max(arr[i] + arr[i-1]+dp[i-3], arr[i]+dp[i-2]);
        // i번째 와인을 마신 경우와 마시지 않은 경우를 비교해준다.
        dp[i] = max(dp[i], dp[i-1]);
        
    }
    
   
    cout << dp[N];
//    for(i=0;i<N;i++){
//        cout << dp[i] << endl;
//    }
    
}

