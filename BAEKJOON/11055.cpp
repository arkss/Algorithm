#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];

int max3(int a, int b, int c)
{
    return max(a, max(b, c));
}

int main()
{
    int N;
    int answer = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        dp[i] = arr[i];
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + arr[i]);
        }
        answer = max3(answer, dp[i], arr[i]);
    }

    cout << answer << "\n";
}