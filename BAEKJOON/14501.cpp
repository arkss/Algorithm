#include <iostream>

using namespace std;

int consult[2][17];
int dp[17];

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> consult[0][i];
        cin >> consult[1][i];
    }

    for (int i = 1; i <= N + 1; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (consult[0][j] + j <= i)
                dp[i] = max(dp[i], dp[j] + consult[1][j]);
        }
    }

    cout << dp[N + 1] << "\n";
}