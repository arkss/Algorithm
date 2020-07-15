#include <iostream>

using namespace std;

int wines[10001];
int dp[10001];

int max3(int a, int b, int c)
{
    return max(max(a, b), c);
}

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> wines[i];
    }
    dp[0] = 0;
    dp[1] = wines[1];
    dp[2] = wines[1] + wines[2];

    for (int i = 3; i <= N; i++)
    {
        dp[i] = max3(dp[i - 3] + wines[i - 1] + wines[i], dp[i - 2] + wines[i], dp[i - 1]);
    }

    cout << dp[N] << "\n";
}
