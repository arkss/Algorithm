/*
아이디어

배열에서 부분증가수열의 최대길이를 구하면 이 수들을 제외한 나머지 수들을 움직이면 된다.
*/

#include <iostream>

using namespace std;


int arr[201];
int dp[201] = {1};


int max(int a, int b)
{
    return a>b ? a:b;
}
int main(int argc, const char * argv[]) {
    int N;
    
    cin >> N;
    int i,j;
    int answer = 0;
    
    for (i=0;i<N;i++){
        cin >> arr[i];
    }
    
    for (i=1;i<N;i++){
        int max = 0;
        for(j=0;j<i;j++){
            if ( arr[i] > arr[j]){
                if (dp[j] > max)
                max = dp[j];
            }
        }
        dp[i] = max+1;
        if (answer < dp[i])
            answer = dp[i];
    }
    cout << N-answer;
    
}
