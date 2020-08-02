#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v;
    vector<int> v_origin;
    map<int, int> m;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    v_origin = v;

    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (!m.count(v[i]))
            m.insert({v[i], cnt++});
    }

    for (int i = 0; i < N; i++)
    {
        cout << m[v_origin[i]] << " ";
    }

    return 0;
}