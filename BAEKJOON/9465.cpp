#include <iostream>
#include <cstring>

using namespace std;

int board[2][100002];

int max3(int a, int b, int c)
{
    return max(a, max(b, c));
}

void print_board(int N)
{
    cout << "\n\n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j <= N + 1; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

int main()
{
    int T;
    cin >> T;
    while (T > 0)
    {
        int N;
        cin >> N;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cin >> board[i][j];
            }
        }
        for (int j = 2; j <= N + 1; j++)
        {
            for (int i = 0; i < 2; i++)
            {
                if (i == 0)
                    board[i][j] = board[i][j] + max3(board[i][j - 2], board[i + 1][j - 1], board[i + 1][j - 2]);
                else
                    board[i][j] = board[i][j] + max3(board[i][j - 2], board[i - 1][j - 1], board[i - 1][j - 2]);
            }
        }
        cout << max(board[0][N], board[1][N]) << "\n";
        memset(board, 0, sizeof(board));
        T--;
    }
}