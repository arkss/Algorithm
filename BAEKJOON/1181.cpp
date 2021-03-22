#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}

int main()
{
    vector<string> v;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), cmp);

    cout << v[0] << "\n";
    for (int i = 1; i < N; i++)
    {
        if (v[i-1] != v[i])
            cout << v[i] << "\n";
    }
}

/*
13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours
*/