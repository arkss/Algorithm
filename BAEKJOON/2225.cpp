#include <iostream>

using namespace std;

// d[i][j] : 정수 i개를 사용해서 합이 j가 되는 경우의 수
int dp[201][201];

void print_dp(int K, int N)
{
    for (int i = 1; i <= K; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout.width(2);
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int N, K;
    cin >> N >> K;

    for (int i = 0; i <= N; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= K; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            for (int k = 0; k <= j; k++)
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 1000000000;
        }
    }

    //print_dp(K, N);

    cout << dp[K][N] << "\n";
}