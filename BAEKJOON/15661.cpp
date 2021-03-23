#include <iostream>
#include <vector>
#include <cstring>
#include <stdlib.h>

using namespace std;

int N;
int board[21][21];
int visited[21];
int minGap = 987654321;

int calcurate_stats(vector<int> v)
{
    int stats = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            stats += board[v[i]][v[j]];
        }
    }
    return stats;
}

void backtracking(int goal, int cnt, int idx)
{
    if (cnt == goal)
    {
        vector<int> team1;
        vector<int> team2;
        //cout << "team1 : ";
        for (int i = 0; i < N; i++)
        {
            if (visited[i])
            {

                //cout << i << " ";
                team1.push_back(i);
            }

            else
                team2.push_back(i);
        }
        int team1Stats = calcurate_stats(team1);
        int team2Stats = calcurate_stats(team2);
        //cout << "team1Stats: " << team1Stats << " team2Stats: " << team2Stats << "\n";
        //cout << "gap: " << abs(team1Stats - team2Stats) << "\n";
        minGap = min(minGap, abs(team1Stats - team2Stats));
        return;
    }
    for (int i = idx; i < N; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            backtracking(goal, cnt + 1, i + 1);
            visited[i] = 0;
        }
    }
}

int main()
{

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    for (int goal = 1; goal < N; goal++)
    {
        //cout << "goal: " << goal << "\n";
        memset(visited, 0, sizeof(visited));
        backtracking(goal, 0, 0);
    }

    cout << minGap << "\n";
}