#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
int N;
int board[51][10];
int answer;
int visited[10];
vector<int> players;

int calculate_score()
{
    int score = 0;
    int player_idx = 0;

    for (int i = 0; i < N; i++)
    {
        int out_cnt = 0;
        int base[3] = {0};
        while (out_cnt != 3)
        {

            int batting = board[i][players[player_idx]];
            player_idx = (player_idx + 1) % 9;
            switch (batting)
            {
            case 1:
                if (base[2])
                {
                    score++;
                    base[2] = 0;
                }

                if (base[1])
                {
                    base[2] = 1;
                    base[1] = 0;
                }

                if (base[0])
                {
                    base[1] = 1;
                    base[0] = 0;
                }
                base[0] = 1;
                break;
            case 2:
                if (base[2])
                {
                    score++;
                    base[2] = 0;
                }

                if (base[1])
                {
                    score++;
                    base[1] = 0;
                }

                if (base[0])
                {
                    base[2] = 1;
                    base[0] = 0;
                }
                base[1] = 1;
                break;
            case 3:
                for (int j = 0; j < 3; j++)
                {
                    if (base[j])
                    {
                        score += base[j];
                        base[j] = 0;
                    }
                }
                base[2] = 1;
                break;
            case 4:
                for (int j = 0; j < 3; j++)
                {
                    if (base[j])
                    {
                        score += base[j];
                        base[j] = 0;
                    }
                }
                score++;
                break;
            case 0:
                out_cnt++;
                break;
            }
        }
    }

    return score;
}

void print_players()
{
    for (int i = 0; i < players.size(); i++)
    {
        cout << players[i] << " ";
    }
    cout << "\n\n";
}

void backtracking(int cnt)
{
    if (cnt == 8)
    {
        players.insert(players.begin() + 3, 1);
        //print_players();
        answer = max(answer, calculate_score());
        players.erase(players.begin() + 3);
        return;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (i == 1)
            continue;
        if (!visited[i])
        {
            visited[i] = 1;
            players.push_back(i);
            backtracking(cnt + 1);
            players.pop_back();
            visited[i] = 0;
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cin >> board[i][j];
        }
    }

    backtracking(0);

    cout << answer << "\n";
}