#include <iostream>
#include <vector>

using namespace std;

int N;
int visited[21];
vector<int> healths;
vector<int> happiness;
int max_happiness;

void backtracking(int now_health, int now_happy, int idx, int meet_num, int meet_goal)
{
    if (meet_num == meet_goal)
    {
        if (now_health > 0)
            max_happiness = max(max_happiness, now_happy);
    }

    for (int i = idx + 1; i < N; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            backtracking(now_health - healths[i], now_happy + happiness[i], i, meet_num + 1, meet_goal);
            visited[i] = 0;
        }
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        healths.push_back(temp);
    }

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        happiness.push_back(temp);
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            backtracking(100 - healths[j], happiness[j], j, 1, i);
        }
    }

    cout << max_happiness << "\n";
}
