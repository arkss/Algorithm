#include <iostream>
#include <vector>

using namespace std;

char board[11][11];
// 상: 0, 우: 1, 하: 2, 좌: 3
vector<int> dirs;
int temp_cnt = 0;
pair<int, int> red;
pair<int, int> blue;
pair<int, int> temp_red;
pair<int, int> temp_blue;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int answer = 987654321;

int move_marble()
{
    bool is_red_hole = false;
    bool is_blue_hole = false;
    for (int i = 0; i < dirs.size(); i++)
    {
        int dir = dirs[i];

        pair<int, int> start_red = temp_red;
        pair<int, int> start_blue = temp_blue;

        // red marble move
        int r_x = temp_red.first;
        int r_y = temp_red.second;

        while (1)
        {

            int r_nx = r_x + dx[dir];
            int r_ny = r_y + dy[dir];

            // 구멍을 만나면 움직인 횟수만큼 반환
            if (board[r_nx][r_ny] == 'O')
            {
                is_red_hole = true;
                break;
            }

            else if (board[r_nx][r_ny] == '#')
            {
                temp_red = {r_x, r_y};
                break;
            }

            else
            {
                r_x = r_nx;
                r_y = r_ny;
            }
        }

        int b_x = temp_blue.first;
        int b_y = temp_blue.second;

        while (1)
        {

            int b_nx = b_x + dx[dir];
            int b_ny = b_y + dy[dir];

            // blue가 구멍에 들어가면 종료
            if (board[b_nx][b_ny] == 'O')
            {
                is_blue_hole = true;
                break;
            }

            else if (board[b_nx][b_ny] == '#')
            {
                temp_blue = {b_x, b_y};
                break;
            }
            else
            {
                b_x = b_nx;
                b_y = b_ny;
            }
        }

        // 두 구슬이 겹쳤을 때 미세조정
        if (temp_red.first == temp_blue.first && temp_red.second == temp_blue.second)
        {
            switch (dir)
            {
            case 0: // 상
                if (start_red.first > start_blue.first)
                    temp_red.first++;
                else
                    temp_blue.first++;
                break;
            case 1: // 우
                if (start_red.second > start_blue.second)
                    temp_blue.second--;
                else
                    temp_red.second--;
                break;
            case 2: // 하
                if (start_red.first > start_blue.first)
                    temp_blue.first--;
                else
                    temp_red.first--;
                break;
            case 3: // 좌
                if (start_red.second > start_blue.second)
                    temp_red.second++;
                else
                    temp_blue.second++;
                break;
            }
        }

        if (is_red_hole && is_blue_hole)
            return 987654321;
        else if (is_red_hole)
            return i + 1;
    }

    return 987654321;
}

void backtracking(int cnt)
{
    if (cnt == 10)
    {

        temp_red = red;
        temp_blue = blue;
        int rst = move_marble();
        answer = min(answer, rst);
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
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                board[i][j] = '.';
                red = {i, j};
            }
            else if (board[i][j] == 'B')
            {
                board[i][j] = '.';
                blue = {i, j};
            }
        }
    }

    backtracking(0);
    if (answer == 987654321)
        cout << -1 << "\n";
    else
        cout << answer << "\n";
}