#include <iostream>
#include <algorithm>

using namespace std;

int board[15001];

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> board[i];

    sort(board, board + N);

    int answer = 0;
    int start = 0;
    int end = N - 1;
    int partial_sum = board[start] + board[end];

    while (start < end)
    {
        if (partial_sum < M)
            start++;
        else if (partial_sum > M)
            end--;
        else if (partial_sum == M)
        {
            start++;
            answer++;
        }
        partial_sum = board[start] + board[end];
    }

    cout << answer << "\n";
}