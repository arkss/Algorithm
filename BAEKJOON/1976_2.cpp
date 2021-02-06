// 플로이드 와샬

#include <iostream>
#include <vector>

using namespace std;

int board[202][202];

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> board[i][j];
            if (i == j)
                board[i][j] = 1;
        }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (board[i][k] && board[k][j])
                {
                    board[i][j] = 1;
                    board[j][i] = 1;
                }

    vector<int> cities;
    for (int i = 0; i < M; i++)
    {
        int city;
        cin >> city;
        cities.push_back(city);
    }

    for (int i = 0; i < M - 1; i++)
    {
        if (!board[cities[i]][cities[i + 1]])
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}