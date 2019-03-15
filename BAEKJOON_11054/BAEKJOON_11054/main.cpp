#include <iostream>

using namespace std;

int arr[1000];
int dp[1000];

int max(int a,int b)
{
    return a>b ? a:b;
}

int main(int argc, const char * argv[]) {
    int N;
    
    cin >> N;
    
    int i,j;
    for(i=0;i<N;i++){
        cin >> arr[i];
    }
    
    for(i=0;i<N;i++){
        int up_max =0;
        for (j=0;j<i;j++){
            if (arr[j] < arr[i] && up_max < dp[j])
                up_max = dp[j];
        }
        dp[i] =up_max + 1;
    }
    
    for(i=0;i<N;i++){
        int down_max = 0;
        for (j=0;j<i;j++){
            if (arr[j] > arr[i] && down_max < dp[j])
                down_max = dp[j];
        }
        dp[i] = max(dp[i], down_max+1);
    }
    
    int result =0;
    for (i=0;i<N;i++){
        if (result < dp[i])
            result = dp[i];
    }
    
    cout << result;
}

