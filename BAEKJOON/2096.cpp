// #include <iostream>

// using namespace std;

// int board[100001][3];
// // [][][1]: max, [][][0]: min
// int my_board[100001][3][2];

// int max(int a, int b)
// {
//     return a > b ? a : b;
// }

// int min(int a, int b)
// {
//     return a < b ? a : b;
// }

// int max3(int a, int b, int c)
// {
//     return max(a, max(b, c));
// }

// int min3(int a, int b, int c)
// {
//     return min(a, min(b, c));
// }

// int make_board(int N, int is_max_board)
// {
//     int result;
//     int (*fp)(int a, int b);
//     int (*fp3)(int a, int b, int c);
//     int k;
//     if (is_max_board)
//     {
//         fp = max;
//         fp3 = max3;
//     }
//     else
//     {
//         fp = min;
//         fp3 = min3;
//     }

//     for (int i = 0; i < 3; i++)
//         my_board[0][i][is_max_board] = board[0][i];

//     for (int i = 1; i < N; i++)
//     {
//         my_board[i][0][is_max_board] = board[i][0] + fp(my_board[i - 1][0][is_max_board], my_board[i - 1][1][is_max_board]);
//         my_board[i][1][is_max_board] = board[i][1] + fp3(my_board[i - 1][0][is_max_board], my_board[i - 1][1][is_max_board], my_board[i - 1][2][is_max_board]);
//         my_board[i][2][is_max_board] = board[i][2] + fp(my_board[i - 1][1][is_max_board], my_board[i - 1][2][is_max_board]);
//     }

//     result = fp3(my_board[N - 1][0][is_max_board], my_board[N - 1][1][is_max_board], my_board[N - 1][2][is_max_board]);

//     return result;
// }

// int main()
// {
//     int N;
//     cin >> N;

//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             cin >> board[i][j];
//         }
//     }

//     int max_result = make_board(N, 1);
//     int min_result = make_board(N, 0);

//     cout << max_result << " " << min_result << "\n";
// }

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