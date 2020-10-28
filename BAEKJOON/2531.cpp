#include <iostream>

using namespace std;

int belt[30001];
int visited[3001];

void print_visited(int d)
{

    for (int i = 1; i <= d; i++)
    {
        cout.width(2);
        cout << visited[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int N, d, k, c;
    cin >> N >> d >> k >> c;

    for (int i = 0; i < N; i++)
    {
        cin >> belt[i];
    }

    visited[c] = 1;
    int answer = 0;
    int temp = 1;

    for (int i = 0; i < k; i++)
    {
        if (!visited[belt[i]])
            temp++;
        visited[belt[i]] += 1;
    }

    int start, end;

    for (int i = 0; i < N; i++)
    {
        start = i;
        end = (start + k) % N;

        visited[belt[start]]--;
        if (visited[belt[start]] == 0)
            temp--;

        if (visited[belt[end]] == 0)
            temp++;
        visited[belt[end]]++;

        answer = max(answer, temp);
    }
    cout << answer;
}