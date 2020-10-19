#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, D;
int board[16][16];
int origin_board[16][16];
int answer;

int visited[16];

struct ENEMY
{
    int x, y;
    bool is_alive;
};

vector<int> archers;
vector<ENEMY> enemies;
vector<ENEMY> origin_enemies;

int calculate_distance(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int kill_enemy()
{
    int kill_cnt = 0;
    vector<int> kill_list;
    for (int i = 0; i < archers.size(); i++)
    {
        //(distance, (y, enemy_num))
        vector<pair<int, pair<int, int>>> enemy_for_archer;
        pair<int, int> archer = {N, archers[i]};
        for (int j = 0; j < enemies.size(); j++)
        {
            ENEMY enemy = enemies[j];
            if (enemy.is_alive)
            {
                int distance = calculate_distance(archer, {enemy.x, enemy.y});
                if (distance <= D)
                    enemy_for_archer.push_back({distance, {enemy.y, j}});
            }
        }
        sort(enemy_for_archer.begin(), enemy_for_archer.end());
        if (enemy_for_archer.size())
        {
            kill_list.push_back(enemy_for_archer[0].second.second);
        }
    }

    for (int i = 0; i < kill_list.size(); i++)
    {
        int enemy_num = kill_list[i];
        if (enemies[enemy_num].is_alive)
        {
            enemies[enemy_num].is_alive = false;
            kill_cnt++;
        }
    }
    return kill_cnt;
}

void move_enemy()
{
    for (int j = 0; j < M; j++)
    {
        for (int i = N - 2; i >= 0; i--)
            board[i + 1][j] = board[i][j];
        board[0][j] = 0;
    }

    for (int i = 0; i < enemies.size(); i++)
    {
        if (enemies[i].is_alive)
        {
            enemies[i].x++;
            if (enemies[i].x == N)
                enemies[i].is_alive = false;
        }
    }
}

bool is_ended()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (board[i][j])
                return false;

    return true;
}

int play_game()
{
    int kill_cnt = 0;
    while (1)
    {
        kill_cnt += kill_enemy();
        move_enemy();
        //print_board();
        if (is_ended())
            break;
    }
    return kill_cnt;
}

void backtracking(int idx, int cnt)
{
    if (cnt == 3)
    {
        memcpy(board, origin_board, sizeof(board));
        enemies = origin_enemies;
        answer = max(answer, play_game());
    }
    for (int i = idx; i < M; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            archers.push_back(i);
            backtracking(i + 1, cnt + 1);
            archers.pop_back();
            visited[i] = 0;
        }
    }
}

int main()
{
    cin >> N >> M >> D;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> origin_board[i][j];
            if (origin_board[i][j])
            {
                origin_enemies.push_back({i, j, true});
            }
        }

    backtracking(0, 0);
    cout << answer << "\n";
    return 0;
}