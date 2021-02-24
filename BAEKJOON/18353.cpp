#include <iostream>
#include <vector>

using namespace std;

vector<int> powers;
int dp[2001];

int main()
{
    int N;
    cin >> N;

    if (N == 1)
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        int power;
        cin >> power;
        powers.push_back(power);
    }

    dp[0] = 1;
    int maxLength = 0;

    for (int i = 1; i < N; i++)
    {
        int tempMaxLength = 0;
        for (int j = 0; j < i; j++)
        {
            if (powers[j] > powers[i])
                if (tempMaxLength < dp[j])
                    tempMaxLength = dp[j];
        }
        dp[i] = tempMaxLength + 1;
        maxLength = max(maxLength, dp[i]);
    }
    /*
    for (int i = 0; i < N; i++)
    {
        cout << dp[i] << " ";
    }
    cout << "\n";
    */
    cout << N - maxLength << "\n";
}
