#include <iostream>
#include <cstring>

using namespace std;

int arr[21];
int answer;
int N, S;
int visited[21];

void print_visited()
{
    for (int i = 0; i < N; i++)
    {

        cout << visited[i] << " ";
    }
    cout << "\n";
}

void backtracking(int idx, int partialSum)
{
    if (idx >= N)
        return;
    if (partialSum + arr[idx] == S)
        answer++;
    backtracking(idx + 1, partialSum + arr[idx]);
    backtracking(idx + 1, partialSum);
}

int main()
{

    cin >> N >> S;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    backtracking(0, 0);

    cout << answer << "\n";
}