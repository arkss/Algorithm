#include <iostream>

using namespace std;

int max3(int a, int b, int c)
{
    return max(a, max(b, c));
}

int min3(int a, int b, int c)
{
    return min(a, min(b, c));
}

int board[2][3][2];

int main()
{
    int max_rst, min_rst;
    int N;
    cin >> N;

    int n1, n2, n3;
    int idx;

    for (int i = 0; i < N; i++)
    {
        cin >> n1 >> n2 >> n3;
        idx = i % 2;
        int oidx = idx ^ 1;
        board[idx][0][0] = n1 + max(board[oidx][0][0], board[oidx][1][0]);
        board[idx][1][0] = n2 + max3(board[oidx][0][0], board[oidx][1][0], board[oidx][2][0]);
        board[idx][2][0] = n3 + max(board[oidx][1][0], board[oidx][2][0]);

        board[idx][0][1] = n1 + min(board[oidx][0][1], board[oidx][1][1]);
        board[idx][1][1] = n2 + min3(board[oidx][0][1], board[oidx][1][1], board[oidx][2][1]);
        board[idx][2][1] = n3 + min(board[oidx][1][1], board[oidx][2][1]);
    }

    max_rst = max3(board[idx][0][0], board[idx][1][0], board[idx][2][0]);
    min_rst = min3(board[idx][0][1], board[idx][1][1], board[idx][2][1]);

    cout << max_rst << " " << min_rst << "\n";
}