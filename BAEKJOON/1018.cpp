#include <iostream>

using namespace std;

// W: 0, B: 1
int board[51][51];

int count_refill(int row, int col)
{
    int refill_cnt_start_w = 0;
    int refill_cnt_start_b = 0;
    for (int i = row; i < row + 8; i++)
    {
        for (int j = col; j < col + 8; j++)
        {
            if ((i + j) % 2 == 0)
            {
                if (board[i][j] == 0)
                    refill_cnt_start_b++;
                else
                    refill_cnt_start_w++;
            }
            else
            {
                if (board[i][j] == 1)
                    refill_cnt_start_b++;
                else
                    refill_cnt_start_w++;
            }
        }
    }
    return min(refill_cnt_start_b, refill_cnt_start_w);
}

void print_board(int M, int N)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int M, N;
    cin >> M >> N;

    for (int i = 0; i < M; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < N; j++)
        {
            if (temp[j] == 'W')
                board[i][j] = 0;
            else
                board[i][j] = 1;
        }
    }

    int min_refill = 32;

    for (int i = 0; i <= M - 8; i++)
    {
        for (int j = 0; j <= N - 8; j++)
        {
            min_refill = min(min_refill, count_refill(i, j));
        }
    }
    cout << min_refill << "\n";
}