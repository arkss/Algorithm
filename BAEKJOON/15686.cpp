#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define INF 987654321

// 0은 빈 칸, 1은 집, 2는 치킨집이다.
int board[51][51];
// dis_board[i][j] : i번째 집에서 j번쨰 치킨집까지의 거리
int dis_board[102][14];
// 도시의 치킨 거리(모든 집의 치킨 거리의 합)의 최솟값
int N, M;
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
int chickens_visited[14];
int city_chicken_distance = INF;

int manhattan_distance(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int calcurate_distance()
{
    int city_distance = 0;

    for (int i = 0; i < houses.size(); i++)
    {
        int chicken_distance = INF;
        for (int j = 0; j < chickens.size(); j++)
        {
            if (chickens_visited[j])
                chicken_distance = min(chicken_distance, dis_board[i][j]);
        }
        city_distance += chicken_distance;
    }
    return city_distance;
}

void backtracking(int idx, int cnt)
{
    if (cnt == M)
    {
        // for (int i = 0; i < chickens.size(); i++)
        // {
        //     cout << chickens_visited[i] << " ";
        // }
        // cout << "\n";
        city_chicken_distance = min(city_chicken_distance, calcurate_distance());
        return;
    }
    for (int i = idx; i < chickens.size(); i++)
    {
        if (!chickens_visited[i])
        {
            chickens_visited[i] = 1;
            backtracking(i, cnt + 1);
            chickens_visited[i] = 0;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
                chickens.push_back({i, j});
            if (board[i][j] == 1)
                houses.push_back({i, j});
        }

    // 거리 미리 저장
    for (int i = 0; i < houses.size(); i++)
    {
        for (int j = 0; j < chickens.size(); j++)
        {
            dis_board[i][j] = manhattan_distance(houses[i], chickens[j]);
        }
    }

    backtracking(0, 0);

    cout << city_chicken_distance << "\n";
}
