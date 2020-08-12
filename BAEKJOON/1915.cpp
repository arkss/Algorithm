#include <iostream>

using namespace std;

int board[1001][1001];

int min3(int a, int b, int c)
{
    return min(a, min(b, c));
}

void print_board(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}
int main()
{
    int answer = 0;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            board[i][j] = temp[j] - '0';
            if (board[i][j])
                answer = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (board[i - 1][j] && board[i][j - 1] && board[i - 1][j - 1] && board[i][j])
                board[i][j] = min3(board[i - 1][j - 1], board[i - 1][j], board[i][j - 1]) + 1;

            answer = max(answer, board[i][j]);
        }
    }
    //print_board(n, m);
    cout << answer * answer << "\n";
}
