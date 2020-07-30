#include <iostream>
#include <queue>

using namespace std;

int cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

int main()
{
    int T;
    cin >> T;
    while (T > 0)
    {
        int N, M;
        cin >> N >> M;
        // 중요도, 순서
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for (int i = 0; i < N; i++)
        {
            int important;
            cin >> important;
            q.push({important, i});
            pq.push(important);
        }
        int cnt = 0;
        while (q.size())
        {
            int important = q.front().first;
            int order = q.front().second;
            q.pop();

            if (pq.top() == important)
            {
                pq.pop();
                cnt++;
                if (order == M)
                {
                    cout << cnt << "\n";
                    break;
                }
            }
            else
                q.push({important, order});
        }

        T--;
    }
}