#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int building_time[1001];
int building_time_total[1001];
int input_cnt[1001];
vector<int> adjust[1001];

int main()
{
    int T;
    cin >> T;

    while (T > 0)
    {
        queue<int> q;
        int N, K;
        cin >> N >> K;

        for (int i = 1; i <= N; i++)
            cin >> building_time[i];

        for (int i = 0; i < K; i++)
        {
            int b1, b2;
            cin >> b1 >> b2;

            adjust[b1].push_back(b2);
            input_cnt[b2]++;
        }

        for (int i = 1; i <= N; i++)
            if (!input_cnt[i])
            {
                q.push(i);
                building_time_total[i] = building_time[i];
            }

        while (!q.empty())
        {
            int now = q.front();
            q.pop();

            for (int i = 0; i < adjust[now].size(); i++)
            {
                int next = adjust[now][i];
                input_cnt[next]--;
                building_time_total[next] = max(building_time_total[next], building_time_total[now] + building_time[next]);
                if (input_cnt[next] == 0)
                    q.push(next);
            }
        }

        int W;
        cin >> W;
        cout << building_time_total[W] << "\n";
        T--;

        memset(building_time, 0, sizeof(building_time));
        memset(building_time_total, 0, sizeof(building_time_total));
        memset(input_cnt, 0, sizeof(input_cnt));
        for (int i = 1; i <= N; i++)
            adjust[i].clear();
    }
}