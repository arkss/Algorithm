#include <iostream>
#include <vector>

using namespace std;
int dp[1001];

int main()
{
    int N;
    cin >> N;

    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);

        dp[i] = 1001;
    }

    dp[0] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j <= v[i]; j++)
        {
            if (i + j < N)
                dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }

    if (dp[N - 1] == 1001)
        cout << -1 << "\n";
    else
        cout << dp[N - 1] << "\n";
}