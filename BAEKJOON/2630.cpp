#include <iostream>

using namespace std;

int board[128][128];
int colorNum[2];

void checkColor(int size, int x, int y)
{

    int startColor = board[x][y];

    if (size == 1)
    {
        colorNum[startColor]++;
        return;
    }

    int isSameColor = true;

    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (board[i][j] != startColor)
            {
                isSameColor = false;
                i = x + size;
                break;
            }
        }
    }

    if (isSameColor)
        colorNum[startColor]++;

    else
    {
        checkColor(size / 2, x, y);
        checkColor(size / 2, x + size / 2, y);
        checkColor(size / 2, x, y + size / 2);
        checkColor(size / 2, x + size / 2, y + size / 2);
    }
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    checkColor(N, 0, 0);

    for (int i = 0; i < 2; i++)
    {
        cout << colorNum[i] << "\n";
    }
}