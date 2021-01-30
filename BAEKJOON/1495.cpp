#include <iostream>
#include <vector>

using namespace std;

// dp[i][j] : i번째 시행에 j 볼륨을 연주할 수 있는지 여부(1, 0)
int dp[102][1002];

void print_dp(int N, int M)
{
    cout << "\n\n";
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {

            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n\n";
}

int main()
{
    int N, S, M;
    cin >> N >> S >> M;

    int volumes[102];

    for (int i = 1; i <= N; i++)
    {
        cin >> volumes[i];
    }

    dp[0][S] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (dp[i - 1][j])
            {
                if (j + volumes[i] <= M)
                    dp[i][j + volumes[i]] = 1;
                if (0 <= j - volumes[i])
                    dp[i][j - volumes[i]] = 1;
            }
        }
    }

    //print_dp(N, M);

    for (int i = M; i >= 0; i--)
    {
        if (dp[N][i])
        {
            cout << i << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
}
