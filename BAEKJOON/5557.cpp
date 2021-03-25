#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;

// dp[i][j] : i번째 숫자까지 사용하여 j의 수를 만들 수 있는 경우의 수
long long dp[101][21];

int main()
{
    int N;
    cin >> N;

    nums.resize(N);

    for (int i = 0; i < N; i++)
        cin >> nums[i];

    dp[0][nums[0]]++;

    for (int i = 1; i < N - 1; i++)
        for (int j = 0; j <= 20; j++)
            if (dp[i - 1][j] >= 0)
            {
                if (0 <= j - nums[i])
                    dp[i][j - nums[i]] += dp[i - 1][j];

                if (j + nums[i] <= 20)
                    dp[i][j + nums[i]] += dp[i - 1][j];
            }

    cout << dp[N - 2][nums[N - 1]] << "\n";
}