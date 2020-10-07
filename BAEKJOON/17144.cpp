#include <iostream>
#include <vector>

using namespace std;

int R, C, T;
int board[51][51];
int spread_board[51][51];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

pair<int, int> air_cleaner;
bool is_find_air_cleaner;
vector<pair<int, int>> dusts;

void spread_dust()
{
    for (int i = 0; i < dusts.size(); i++)
    {
        pair<int, int> dust = dusts[i];
        int x = dust.first;
        int y = dust.second;

        int spread_cnt = 0;

        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if (!(0 <= nx && nx < R && 0 <= ny && ny < C))
                continue;
            if (board[nx][ny] == -1)
                continue;

            spread_board[nx][ny] += board[x][y] / 5;
            spread_cnt++;
        }

        board[x][y] = board[x][y] - (board[x][y] / 5 * spread_cnt);
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            board[i][j] += spread_board[i][j];
        }
    }
}

void print_board()
{
    cout << "\n\n";
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout.width(2);
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

void operate_air_cleaner()
{
    int x = air_cleaner.first; // 2
    // 위쪽 사이클
    // 하 1=0
    for (int i = x - 2; i >= 0; i--)
        board[i + 1][0] = board[i][0];
    // 좌 0=1 1=2 ... 6=7
    for (int i = 0; i < C - 1; i++)
        board[0][i] = board[0][i + 1];
    // 상 0=1 1=2
    for (int i = 0; i < x; i++)
        board[i][C - 1] = board[i + 1][C - 1];
    // 우 7=6 6=5 ... 2=1
    for (int i = C - 1; i > 1; i--)
        board[x][i] = board[x][i - 1];
    board[x][1] = 0;

    x = air_cleaner.second; // 3 , R: 7 , C : 8
    // 아래쪽 사이클
    // 상 4=5 5=6
    for (int i = x + 2; i < R; i++)
        board[i - 1][0] = board[i][0];
    // 좌 0=1 1=2 ... 6=7
    for (int i = 0; i < C - 1; i++)
        board[R - 1][i] = board[R - 1][i + 1];
    // 하 : 5 4 3
    for (int i = R - 2; i >= x; i--)
        board[i + 1][C - 1] = board[i][C - 1];
    // 우  7=6 6=5 ... 2=1
    for (int i = C - 1; i > 1; i--)
        board[x][i] = board[x][i - 1];
    board[x][1] = 0;
}

void init_spread_board()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            spread_board[i][j] = 0;
        }
    }
}

int count_all_dusts()
{
    int answer = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (board[i][j] > 0)
                answer += board[i][j];
        }
    }
    return answer;
}

int main()
{

    cin >> R >> C >> T;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];
            if (board[i][j] > 0)
                dusts.push_back({i, j});
            if (!is_find_air_cleaner && board[i][j] == -1)
            {
                is_find_air_cleaner = true;
                air_cleaner = {i, i + 1};
            }
        }
    }

    for (int i = 0; i < T; i++)
    {
        spread_dust();

        //print_board();

        operate_air_cleaner();
        dusts.clear();
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (board[i][j] > 0)
                {
                    dusts.push_back({i, j});
                }
            }
        }
        init_spread_board();
    }

    //print_board();

    cout << count_all_dusts() << "\n";
}