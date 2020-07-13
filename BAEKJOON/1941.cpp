#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

char board[5][5];
bool visited[5][5];
int nums[25];
int answer;

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

pair<int, int> num_to_rc(int num)
{
    pair<int, int> p;
    p.first = num / 5;
    p.second = num % 5;
    return p;
}

bool check_over_4_S()
{
    int s_cnt = 0;
    for (int i = 0; i < 25; i++)
    {
        if (nums[i] == 1)
        {
            pair<int, int> p = num_to_rc(i);
            if (board[p.first][p.second] == 'S')
                s_cnt++;
        }
    }
    return s_cnt >= 4;
}

bool check_connect()
{
    int board_7[5][5];
    int connected_cnt = 1;
    queue<pair<int, int>> q;

    memset(board_7, 0, sizeof(board_7));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < 25; i++)
    {
        if (nums[i])
        {
            pair<int, int> temp = num_to_rc(i);

            board_7[temp.first][temp.second] = 1;
            if (q.empty())
            {
                q.push(temp);
                visited[temp.first][temp.second] = 1;
            }
        }
    }

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (connected_cnt == 7)
            break;

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 <= nr && nr < 5 && 0 <= nc && nc < 5)
            {
                if (board_7[nr][nc] && !visited[nr][nc])
                {
                    visited[nr][nc] = 1;
                    q.push(make_pair(nr, nc));
                    connected_cnt++;
                }
            }
        }
    }
    return connected_cnt == 7;
}

void print_nums()
{
    for (int i = 0; i < 25; i++)
    {
        if (nums[i])
            cout << i << " ";
    }
    cout << "\n";
}

void backtracking(int idx, int cnt)
{
    if (cnt == 7)
    {
        // S가 4개 이상인지 확인
        if (check_over_4_S())
        {
            // 7개가 연결되어 있는지 확인
            if (check_connect())
            {
                //print_nums();
                answer++;
            }
        }
    }
    else
    {
        for (int i = idx; i < 25; i++)
        {
            if (!nums[i])
            {
                nums[i] = 1;
                backtracking(i, cnt + 1);
                nums[i] = 0;
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < 5; j++)
        {
            board[i][j] = temp[j];
        }
    }

    backtracking(0, 0);
    cout << answer << "\n";
}