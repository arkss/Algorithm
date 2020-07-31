#include <iostream>

using namespace std;

int board[21][21];

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

struct DICE
{
    int top;
    int right;
    int left;
    int bottom;
    int front;
    int back;
};

DICE dice;

void rolling_dice(int command)
{
    switch (command)
    {
        int temp;
    // 동
    case 1:
        temp = dice.right;
        dice.right = dice.top;
        dice.top = dice.left;
        dice.left = dice.bottom;
        dice.bottom = temp;
        break;
    // 서
    case 2:
        temp = dice.right;
        dice.right = dice.bottom;
        dice.bottom = dice.left;
        dice.left = dice.top;
        dice.top = temp;
        break;
    // 북
    case 3:
        temp = dice.back;
        dice.back = dice.top;
        dice.top = dice.front;
        dice.front = dice.bottom;
        dice.bottom = temp;
        break;
    // 남
    case 4:
        temp = dice.back;
        dice.back = dice.bottom;
        dice.bottom = dice.front;
        dice.front = dice.top;
        dice.top = temp;
        break;
    }
}

void print_board(int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

void print_dice(DICE dice)
{
    cout << "top: " << dice.top << "\n";
    cout << "back: " << dice.back << "\n";
    cout << "bottom: " << dice.bottom << "\n";
    cout << "front: " << dice.front << "\n";
    cout << "left: " << dice.left << "\n";
    cout << "right: " << dice.right << "\n";
    cout << "\n";
}

int main()
{
    int N, M, x, y, k;
    cin >> N >> M >> x >> y >> k;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        int command;
        cin >> command;

        int nx = x + dx[command];
        int ny = y + dy[command];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;

        rolling_dice(command);
        if (board[nx][ny] == 0)
            board[nx][ny] = dice.bottom;
        else
        {
            dice.bottom = board[nx][ny];
            board[nx][ny] = 0;
        }

        // print_board(N, M);
        // print_dice(dice);

        x = nx;
        y = ny;

        cout << dice.top << "\n";
    }
}