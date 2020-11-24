#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int arr[8];
int answer;
int N;
int visited[10];

void backtracking(int cnt, vector<int> v)
{
    if (cnt == N)
    {
        int result = 0;
        for (int i = 0; i < v.size() - 1; i++)
        {
            result += abs(v[i] - v[i + 1]);
        }
        answer = max(answer, result);
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            v.push_back(arr[i]);
            backtracking(cnt + 1, v);
            v.pop_back();
            visited[i] = 0;
        }
    }
}

int main()
{

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    vector<int> v;

    backtracking(0, v);

    cout << answer << "\n";
}