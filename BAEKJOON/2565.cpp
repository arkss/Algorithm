#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[501];

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}

int main()
{
    int N;
    cin >> N;

    int lis = 0;

    vector<pair<int, int>> poles;

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        poles.push_back({a, b});
    }

    sort(poles.begin(), poles.end(), cmp);

    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        int now = poles[i].second;
        for (int j = 0; j < i; j++)
        {
            if (now > poles[j].second && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
        lis = max(lis, dp[i]);
    }

    cout << N - lis << "\n";
}