#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100001];

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first < b.first;
}

void print_dp(int K)
{
    for (int i = 1; i <= K; i++)
    {
        cout << dp[i] << " ";
    }
    cout << "\n";
}

int max3(int a, int b, int c)
{
    return max(max(a, b), c);
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> v;

    for (int i = 0; i < N; i++)
    {
        int W, V;
        cin >> W >> V;
        v.push_back(make_pair(W, V));
    }

    sort(v.begin(), v.end(), cmp);
    for (int j = 0; j < N; j++)
    {
        for (int i = K; i >= 1; i--)
        {
            int W = v[j].first;
            int V = v[j].second;
            if (i >= W)
                dp[i] = max(dp[i], dp[i - W] + V);
        }
    }

    cout << dp[K] << "\n";
}
