#include <iostream>

using namespace std;

int board[1001][1001];
int checkMax[1001][1001];

int main()
{
    long long answer = 0;
    int H, W;
    cin >> H >> W;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> board[i][j];

    for (int i = 0; i < H; i++)
    {
        int maxIdx = -1;
        int maxValue = -1;
        for (int j = 0; j < W; j++)
        {
            if (board[i][j] > maxValue)
            {
                maxValue = board[i][j];
                maxIdx = j;
            }
        }
        checkMax[i][maxIdx] = 1;
    }

    for (int j = 0; j < W; j++)
    {
        int maxIdx = -1;
        int maxValue = -1;
        for (int i = 0; i < H; i++)
        {
            if (board[i][j] > maxValue)
            {
                maxValue = board[i][j];
                maxIdx = i;
            }
        }
        checkMax[maxIdx][j] = 1;
    }

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
        {
            if (!checkMax[i][j])
            {

                answer += board[i][j];
            }
        }

    cout << answer << "\n";
}