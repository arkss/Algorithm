#include <iostream>

using namespace std;

int number[2001];
// i 번째 수부터 j 번째 수가 팰린드롬을 이루는지 여부
int dp[2001][2001];

int main() {
    
    int N,M;
    cin >> N;


    for (int i=1;i<=N;i++){
        cin >> number[i];
    }

    // 길이가 1일 때
    for (int i=1;i<=N;i++){
        dp[i][i] = 1;
    }
    // 길이가 2일 때
    for (int i=1;i<=N-1;i++){
        if (number[i]==number[i+1]) dp[i][i+1] = 1;
    }
    // 길이가 3 이상일 때
    for (int k=3;k<=N;k++){
        for(int i=1;i<=N-k+1;i++){
            int j=i+k-1;
            if (number[i]==number[j] && dp[i+1][j-1])
                dp[i][j] = 1;
        }
    }

    cin >> M;
    for (int i=0;i<M;i++){
        int start, end;
        scanf("%d%d", &start, &end);
        printf("%d\n", dp[start][end]);
    }


    return 0;
}

