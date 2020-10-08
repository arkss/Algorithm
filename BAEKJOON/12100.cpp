#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N;
int board[21][21];
int temp_board[21][21];

vector<int> dirs;
int answer;

void print_board()
{
    cout << "\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << temp_board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

//  한 번의 이동에서 이미 합쳐진 블록은 또 합쳐질 수 없기 때문이다.
int move_board()
{
    memcpy(temp_board, board, sizeof(temp_board));
    queue<int> q;
    int max_block = 0;
    for (int dir_idx = 0; dir_idx < dirs.size(); dir_idx++)
    {
        int dir = dirs[dir_idx];
        switch (dir)
        {

        case 0: // 우
            for (int i = 0; i < N; i++)
            {
                for (int j = N - 1; j >= 0; j--)
                {
                    if (temp_board[i][j])
                        q.push(temp_board[i][j]);
                    temp_board[i][j] = 0;
                }

                int idx = N - 1;
                while (!q.empty())
                {
                    int value = q.front();
                    q.pop();

                    if (temp_board[i][idx] == 0)
                        temp_board[i][idx] = value;
                    else if (temp_board[i][idx] == value)
                        temp_board[i][idx--] += value;
                    else
                        temp_board[i][--idx] = value;
                }
            }
            break;
        case 1: // 좌
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (temp_board[i][j])
                        q.push(temp_board[i][j]);
                    temp_board[i][j] = 0;
                }

                int idx = 0;
                while (!q.empty())
                {
                    int value = q.front();
                    q.pop();

                    if (temp_board[i][idx] == 0)
                        temp_board[i][idx] = value;
                    else if (temp_board[i][idx] == value)
                        temp_board[i][idx++] += value;
                    else
                        temp_board[i][++idx] = value;
                }
            }
            break;
        case 2: // 하
            for (int i = 0; i < N; i++)
            {
                for (int j = N - 1; j >= 0; j--)
                {
                    if (temp_board[j][i])
                        q.push(temp_board[j][i]);
                    temp_board[j][i] = 0;
                }

                int idx = N - 1;
                while (!q.empty())
                {
                    int value = q.front();
                    q.pop();

                    if (temp_board[idx][i] == 0)
                        temp_board[idx][i] = value;
                    else if (temp_board[idx][i] == value)
                        temp_board[idx--][i] += value;
                    else
                        temp_board[--idx][i] = value;
                }
            }
            break;
        case 3: // 상
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (temp_board[j][i])
                        q.push(temp_board[j][i]);
                    temp_board[j][i] = 0;
                }

                int idx = 0;
                while (!q.empty())
                {
                    int value = q.front();
                    q.pop();

                    if (temp_board[idx][i] == 0)
                        temp_board[idx][i] = value;
                    else if (temp_board[idx][i] == value)
                        temp_board[idx++][i] += value;
                    else
                        temp_board[++idx][i] = value;
                }
            }
            break;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            max_block = max(max_block, temp_board[i][j]);
        }
    }

    return max_block;
}

void backtracking(int cnt)
{
    if (cnt == 5)
    {
        answer = max(answer, move_board());
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        dirs.push_back(i);
        backtracking(cnt + 1);
        dirs.pop_back();
    }
}

int main()
{

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    backtracking(0);

    cout << answer << "\n";
}