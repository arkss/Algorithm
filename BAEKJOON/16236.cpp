#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int board[21][21];
int visited[21][21];

// <r,c>, distance
vector<pair<pair<int, int>, int>> eats;

// 상, 좌, 하, 우 순으로 탐색
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int shake_size = 2;
int rest_until_next = 2;

void BFS(int r, int c, int N)
{
    queue<pair<int, int>> q;
    int distance = 21 * 21;

    q.push(make_pair(r, c));
    while (1)
    {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 <= nr && nr < N && 0 <= nc && nc < N)
                if (!visited[nr][nc] && shake_size >= board[nr][nc])
                {

                    visited[nr][nc] = visited[r][c] + 1;
                    q.push(make_pair(nr, nc));

                    // 먹을 수 있는 먹이를 발견한 경우
                    if (board[nr][nc] && board[nr][nc] < shake_size)
                    {
                        // 가장 가까운 먹이를 먹는 경우
                        if (visited[nr][nc] <= distance)
                        {
                            distance = visited[nr][nc];
                            eats.push_back(make_pair(make_pair(nr, nc), distance));
                        }
                    }
                }
        }
        if (q.empty())
            break;
    }
}

void reset_visited(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = false;
        }
    }
}

void print_board(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if (a.second == b.second)
    {
        if (a.first.first != b.first.first)
        {
            return a.first.first < b.first.first;
        }
        return a.first.second < b.first.second;
    }
    {
        return a.second < b.second;
    }
}

int main()
{
    int N;
    cin >> N;
    int r, c;
    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                board[i][j] = 0;
                r = i;
                c = j;
            }
        }
    }
    while (1)
    {
        // TODO: memset 어떻게 쓰더라
        reset_visited(N);
        BFS(r, c, N);
        if (eats.size())
        {
            sort(eats.begin(), eats.end(), cmp);
            rest_until_next--;
            if (rest_until_next == 0)
            {
                shake_size++;
                rest_until_next = shake_size;
            }
            r = eats[0].first.first;
            c = eats[0].first.second;
            cnt += eats[0].second;
            eats.clear();
            board[r][c] = 0;
        }
        else
            break;
    }

    //print_board(N);
    cout << cnt << "\n";
}