#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
// 0: 빈 칸, -1: 벽, 자연수: 승객번호
int board[21][21];
int visited[21][21];
// 상 좌 하 우
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
struct TAXI
{
    int x, y;
    int fuel;
};

struct PASSANGER
{
    int p_x, p_y;
    int d_x, d_y;
};

struct FINDED
{
    int x, y;
    int distance;
    int p_num;
};

TAXI taxi;
PASSANGER passanger[21 * 21];
vector<FINDED> finded;

void print_taxi()
{
    cout << "현재위치: " << taxi.x << " " << taxi.y << "\n";
    cout << "연료량: " << taxi.fuel << "\n\n";
}

void print_visited()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}

bool is_in_board(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < N;
}

bool cmp(FINDED f1, FINDED f2)
{
    /* 조건에 맞는 손님을 찾기 위해서 Vector를 정렬하기 위한 기준 설정. */
    if (f1.distance <= f2.distance)
    {
        if (f1.distance == f2.distance)
        {
            if (f1.x <= f2.x)
            {
                if (f1.x == f2.x)
                {
                    if (f1.y < f2.y)
                    {
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

int find_passanger()
{
    memset(visited, 0, sizeof(visited));
    finded.clear();
    // (distance,x),(y, fuel)
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, taxi.x}, {taxi.y, taxi.fuel}});

    int start_fuel = taxi.fuel;
    visited[taxi.x][taxi.y] = 1;

    while (!q.empty())
    {

        int distance = q.front().first.first;
        int x = q.front().first.second;
        int y = q.front().second.first;
        int rest_fuel = q.front().second.second;

        q.pop();

        if (board[x][y] >= 1)
            finded.push_back({x, y, distance, board[x][y]});
        if (rest_fuel == 0)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!is_in_board(nx, ny))
                continue;
            if (board[nx][ny] == -1)
                continue;
            if (visited[nx][ny] == 1)
                continue;

            visited[nx][ny] = 1;
            q.push({{distance + 1, nx}, {ny, rest_fuel - 1}});
        }
    }

    if (finded.empty())
        return -1;
    sort(finded.begin(), finded.end(), cmp);
    board[finded[0].x][finded[0].y] = 0;
    taxi.fuel -= finded[0].distance;
    return finded[0].p_num;
}

bool find_destination(int num)
{
    int p_x = passanger[num].p_x, p_y = passanger[num].p_y;
    int d_x = passanger[num].d_x, d_y = passanger[num].d_y;
    memset(visited, 0, sizeof(visited));
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, p_x}, {p_y, taxi.fuel}});
    visited[p_x][p_y] = 1;

    while (!q.empty())
    {
        int distance = q.front().first.first;
        int x = q.front().first.second;
        int y = q.front().second.first;
        int rest_fuel = q.front().second.second;
        q.pop();
        if (x == d_x && y == d_y)
        {
            taxi.fuel = rest_fuel + distance * 2;
            taxi.x = x;
            taxi.y = y;
            return true;
        }
        if (rest_fuel == 0)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!is_in_board(nx, ny))
                continue;
            if (board[nx][ny] == -1)
                continue;
            if (visited[nx][ny] == 1)
                continue;

            visited[nx][ny] = 1;
            q.push({{distance + 1, nx}, {ny, rest_fuel - 1}});
        }
    }
    return false;
}

int main()
{
    cin >> N >> M >> taxi.fuel;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                board[i][j] = -1;
        }
    }

    cin >> taxi.x >> taxi.y;
    taxi.x--;
    taxi.y--;

    for (int i = 1; i <= M; i++)
    {
        int p_x, p_y, dest_x, dest_y;
        cin >> p_x >> p_y >> dest_x >> dest_y;
        p_x--;
        p_y--;
        dest_x--;
        dest_y--;

        passanger[i] = {p_x, p_y, dest_x, dest_y};
        board[p_x][p_y] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int p_num = find_passanger();
        // cout << "p_num:" << p_num << "\n";
        // print_taxi();
        if (p_num == -1)
        {
            cout << -1 << "\n";
            return 0;
        }

        bool is_find = find_destination(p_num);
        // cout << "is_find: " << is_find << "\n";
        // print_taxi();
        if (!is_find)
        {
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << taxi.fuel << "\n";
}