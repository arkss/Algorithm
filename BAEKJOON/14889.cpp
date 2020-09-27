#include <iostream>
#include <cstdlib>

using namespace std;

int board[21][21];
// 1이면 A팀, 0이면 B팀
int team[21];

int min_gap = 987654321;

int calcurate_ability(int N, int team_num)
{
    int ability = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (team[i] == team_num && team[j] == team_num)
                ability += board[i][j];
        }
    }
    return ability;
}

void backtracking(int N, int cnt, int idx)
{
    if (N / 2 == cnt)
    {
        int teamA_ability = calcurate_ability(N, 1);
        int teamB_ability = calcurate_ability(N, 0);
        min_gap = min(min_gap, abs(teamA_ability - teamB_ability));
    }
    else
    {
        for (int i = idx; i < N; i++)
        {
            if (!team[i])
            {
                team[i] = 1;
                backtracking(N, cnt + 1, i);
                team[i] = 0;
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    backtracking(N, 0, 0);

    cout << min_gap << "\n";
}