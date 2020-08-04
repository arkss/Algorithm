#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

int distance(pair<int, int> a, pair<int, int> b)
{
    return abs(b.first - a.first) + abs(b.second - a.second);
}

bool bfs(pair<int, int> home, vector<pair<int, int>> stores, pair<int, int> festival)
{
    queue<pair<int, int>> q;
    q.push(home);
    int visited[stores.size()];
    for (int i = 0; i < stores.size(); i++)
    {
        visited[i] = 0;
    }

    while (!q.empty())
    {
        pair<int, int> next = q.front();
        q.pop();

        if (distance(next, festival) <= 1000)
            return true;

        for (int i = 0; i < stores.size(); i++)
        {
            if (!visited[i] && distance(next, stores[i]) <= 1000)
            {
                visited[i] = 1;
                q.push(stores[i]);
            }
        }
    }
    return false;
}

int main()
{
    int T;
    cin >> T;

    while (T > 0)
    {
        vector<pair<int, int>> stores;
        pair<int, int> home;
        pair<int, int> store;
        pair<int, int> festival;
        int store_num;
        cin >> store_num;
        cin >> home.first >> home.second;

        for (int i = 0; i < store_num; i++)
        {
            cin >> store.first >> store.second;
            stores.push_back(store);
        }
        cin >> festival.first >> festival.second;

        if (bfs(home, stores, festival))
            cout << "happy\n";
        else
            cout << "sad\n";

        T--;
    }
}