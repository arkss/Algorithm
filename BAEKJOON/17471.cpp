#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int population_nums[11];
vector<int> adjust[11];
int answer = INF;
int N;
int visited[11];
vector<int> areas[2];

bool is_connected(int area_num)
{
    // 해당 bfs에서 방문한 것을 체크
    int temp_visited[11] = {};
    int cnt = 1;
    queue<int> q;

    int start = areas[area_num][0];
    q.push(start);
    temp_visited[start] = 1;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < adjust[now].size(); i++)
        {
            int next = adjust[now][i];
            // 다른 area로 넘어가는 것을 방지
            if (area_num == 0 && !visited[next])
                continue;
            if (area_num == 1 && visited[next])
                continue;
            if (temp_visited[next])
                continue;
            temp_visited[next] = 1;
            q.push(next);
            cnt++;
        }
    }
    // 현재구역의 시작점에서 bfs 탐색 결과가 구역의 크기가 같으면 True
    return areas[area_num].size() == cnt;
}

void backtracking(int idx, int cnt)
{
    if (cnt >= 1)
    {

        for (int i = 1; i <= N; i++)
        {
            if (visited[i])
                areas[0].push_back(i);
            else
                areas[1].push_back(i);
        }

        if (areas[0].empty() || areas[1].empty())
            return;

        if (is_connected(0) && is_connected(1))
        {
            int area_num[2] = {};
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < areas[i].size(); j++)
                {
                    area_num[i] += population_nums[areas[i][j]];
                }
            }

            int diff = abs(area_num[0] - area_num[1]);
            answer = min(answer, diff);
        }

        for (int i = 0; i < 2; i++)
        {
            areas[i].clear();
        }
    }

    for (int i = idx; i <= N; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            backtracking(i + 1, cnt + 1);
            visited[i] = 0;
        }
    }
}

int main()
{

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> population_nums[i];
    }

    for (int i = 1; i <= N; i++)
    {
        int adjust_cnt;
        cin >> adjust_cnt;
        for (int j = 0; j < adjust_cnt; j++)
        {
            int adjust_area;
            cin >> adjust_area;
            adjust[i].push_back(adjust_area);
        }
    }

    backtracking(1, 0);

    if (answer == INF)
        cout << "-1\n";
    else
        cout << answer << "\n";
    return 0;
}
