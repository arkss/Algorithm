#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

int board[51][51];
int visited[51][51];
vector<pair<int, int>> unions[2501];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void print_board(int N)
{
    cout << "\n\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

void bfs(int i, int j, int union_num, int N, int L, int R)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    unions[union_num].push_back({i, j});
    visited[i][j] = 1;

    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();

        int x = now.first;
        int y = now.second;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (visited[nx][ny])
                continue;
            int difference = abs(board[x][y] - board[nx][ny]);
            if (L <= difference && difference <= R)
            {
                unions[union_num].push_back({nx, ny});
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

int create_union(int N, int L, int R)
{
    int union_num = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                bfs(i, j, union_num++, N, L, R);
            }
        }
    return union_num;
}

void move_population(int union_num)
{
    for (int i = 0; i < union_num; i++)
    {
        int union_sum = 0;
        int union_size = unions[i].size();
        if (union_size == 1)
            continue;
        for (int j = 0; j < union_size; j++)
            union_sum += board[unions[i][j].first][unions[i][j].second];

        int union_avg = union_sum / union_size;
        for (int j = 0; j < union_size; j++)
            board[unions[i][j].first][unions[i][j].second] = union_avg;
    }
}

void reset_visited_and_unions(int N)
{
    for (int i = 0; i < N; i++)
        memset(visited[i], 0, sizeof(visited));

    for (int i = 0; i < N * N; i++)
        unions[i].clear();
}

int main()
{
    int N, L, R;
    cin >> N >> L >> R;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    int move_cnt = 0;
    int union_num;
    while (1)
    {
        // 연합 생성
        union_num = create_union(N, L, R);
        if (union_num == N * N)
            break;
        // 인구 이동
        move_population(union_num);
        reset_visited_and_unions(N);
        move_cnt++;
    }
    cout << move_cnt << "\n";
}