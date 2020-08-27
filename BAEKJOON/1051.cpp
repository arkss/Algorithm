#include <iostream>

using namespace std;

int board[51][51];

int main()
{
    int N, M;
    cin >> N >> M;

    int max_size = 0;

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
            board[i][j] = temp[j] - '0';
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {

            int left_top = board[i][j];
            for (int k = j + 1; k < M; k++)
            {
                //cout << i << " " << j << " " << k << "\n";
                if (k == M)
                    break;
                int right_top = board[i][k];
                if (left_top == right_top)
                {
                    int distance = k - j;
                    if (i + distance >= N)
                        continue;
                    //cout << "distance:" << distance << "\n";
                    int left_bottom = board[i + distance][j];
                    int right_bottom = board[i + distance][k];
                    if (left_top == left_bottom && left_top == right_bottom)
                    {
                        max_size = max(max_size, distance + 1);
                    }
                }
            }
        }
    if (max_size == 0)
        cout << 1 << "\n";
    else
        cout << max_size * max_size << "\n";
}