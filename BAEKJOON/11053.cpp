#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        dp[i] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
    }

    int max_l = 0;

    for (int i = 1; i <= N; i++)
    {
        if (dp[i] > max_l)
            max_l = dp[i];
    }
    cout << max_l;
}