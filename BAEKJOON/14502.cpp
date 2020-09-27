#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
// 0:빈칸 1:벽 2:바이러스
int origin_board[9][9];
int board[9][9];
int virus_board[9][9];
int visited[9][9];

vector<pair<int, int>> virus_point;
int empty_point_visited[9][9];
int max_safe_place;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void print_board()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

void print_virus_board()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << virus_board[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

void reset_visited()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            visited[i][j] = 0;
}

void bfs(pair<int, int> p)
{

    queue<pair<int, int>> q;
    q.push(p);

    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < M)
            {
                if (!virus_board[nx][ny])
                {
                    virus_board[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
    }
}

void move_virus()
{
    memcpy(virus_board, board, sizeof(board));
    for (int i = 0; i < virus_point.size(); i++)
    {
        bfs(virus_point[i]);
    }
    reset_visited();
    //print_virus_board();
}

int count_safe_place()
{
    int num = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (virus_board[i][j] == 0)
                num++;
    return num;
}

void backtracking(int cnt)
{
    if (cnt == 2)
    {
        move_virus();
        max_safe_place = max(max_safe_place, count_safe_place());
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] == 0)
                {
                    board[i][j] = 1;
                    backtracking(cnt + 1);
                    board[i][j] = 0;
                }
            }
        }
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
            origin_board[i][j] = board[i][j];

            if (board[i][j] == 2)
                virus_point.push_back({i, j});
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 0)
            {
                memcpy(board, origin_board, sizeof(origin_board));

                board[i][j] = 1;
                backtracking(0);
                board[i][j] = 0;
            }
        }
    }

    cout << max_safe_place << "\n";
}