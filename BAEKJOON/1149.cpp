#include <iostream>
#include <algorithm>

using namespace std;

int board[1001][3];

int min_3(int a, int b, int c)
{
    return min(min(a, b), c);
}

void print_board(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int min_v = 987654321;
            for (int k = 0; k < 3; k++)
            {
                if (j != k)
                {
                    min_v = min(min_v, board[i - 1][k]);
                }
            }
            board[i][j] += min_v;
        }
    }

    //print_board(N);

    cout << min_3(board[N - 1][0], board[N - 1][1], board[N - 1][2]) << "\n";
}
