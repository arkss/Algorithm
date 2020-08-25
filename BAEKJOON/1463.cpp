// #include <iostream>
// #include <algorithm>

// using namespace std;

// int dp[1000001];

// int main()
// {
//     int N;
//     cin >> N;

//     dp[1] = 0;

//     for (int i = 2; i <= N; i++)
//     {
//         dp[i] = dp[i - 1];
//         if (i % 3 == 0)
//             dp[i] = min(dp[i], dp[i / 3]);
//         if (i % 2 == 0)
//             dp[i] = min(dp[i], dp[i / 2]);
//         dp[i]++;
//     }

//     cout << dp[N] << "\n";
// }

#include <iostream>

using namespace std;

int dp[1000001];

int main()
{
    int N;
    cin >> N;
    dp[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);
    }

    // for (int i = 1; i <= N; i++)
    //     cout << dp[i] << " ";

    cout << dp[N] << "\n";
}