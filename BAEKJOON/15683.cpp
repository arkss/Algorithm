/*
방향만 다 결정한 후에 한 번에 #을 채워주자.

*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int temp_board[9][9];
int board[9][9];
int N, M;
int min_blind_spot = 100;

// (cctv num, (x,y))
vector<pair<int, pair<int, int>>> cctvs;
int cctvs_dir[8];

int print_board_call_cnt = 0;

void print_board()
{
    cout << print_board_call_cnt++ << "\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout.width(3);
            cout << temp_board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void go_straight(int x, int y, int dir)
{
    // dir) 0: 위, 1: 오른, 2: 아래, 3: 왼
    while (1)
    {
        if (dir == 0)
            x--;
        else if (dir == 1)
            y++;
        else if (dir == 2)
            x++;
        else if (dir == 3)
            y--;

        if (!(0 <= x && x < N && 0 <= y && y < M))
            return;
        if (temp_board[x][y] == 6)
            return;

        temp_board[x][y] = -1;
    }
}

void create_watch_area()
{
    memcpy(temp_board, board, sizeof(board));
    for (int i = 0; i < cctvs.size(); i++)
    {
        pair<int, pair<int, int>> cctv = cctvs[i];
        int cctv_num = cctv.first;
        int x = cctv.second.first;
        int y = cctv.second.second;

        switch (cctv_num)
        {
        case 1:
            go_straight(x, y, cctvs_dir[i]);
            break;
        case 2:
            go_straight(x, y, cctvs_dir[i]);
            go_straight(x, y, (cctvs_dir[i] + 2) % 4);
            break;
        case 3:
            go_straight(x, y, cctvs_dir[i]);
            go_straight(x, y, (cctvs_dir[i] + 1) % 4);
            break;
        case 4:
            for (int j = 0; j < 3; j++)
                go_straight(x, y, (cctvs_dir[i] + j) % 4);

            break;
        case 5:
            for (int i = 0; i < 4; i++)
                go_straight(x, y, i);
            break;
        }
    }
}

int count_blind_spot()
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (temp_board[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}

void backtracking(int cnt)
{
    if (cnt == cctvs.size())
    {
        // for (int i = 0; i < cctvs.size(); i++)
        // {
        //     cout << cctvs_dir[i] << " ";
        // }
        // cout << "\n";
        create_watch_area();

        min_blind_spot = min(min_blind_spot, count_blind_spot());
        //print_board();
        return;
    }

    for (int j = 0; j < 4; j++)
    {
        cctvs_dir[cnt] = j;
        backtracking(cnt + 1);
    }
}

int main()
{

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];

            if (board[i][j] != 0 && board[i][j] != 6)
            {
                cctvs.push_back({board[i][j], {i, j}});
            }
        }
    }

    backtracking(0);

    cout << min_blind_spot << "\n";
}