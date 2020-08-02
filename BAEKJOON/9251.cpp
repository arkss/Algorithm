#include <iostream>
#include <string>

using namespace std;

int dp[1002][1002];

void print_dp(int M, int N)
{
    for (int i = 0; i <= M; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    string s1, s2;
    cin >> s2 >> s1;

    s1 = " " + s1;
    s2 = " " + s2;

    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i] == s2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[s1.size() - 1][s2.size() - 1] << "\n";
}