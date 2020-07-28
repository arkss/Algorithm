#include <iostream>
#include <queue>

using namespace std;

int board[101][101];
int visited[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void board_and_visited_init(int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = 0;
            if (board[i][j] == 2)
                board[i][j] = 0;
        }
    }
}

void print_board(int N, int M)
{
    cout << "\n\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

int bfs(int N, int M, int x, int y)
{
    //print_board(N, M);
    queue<pair<int, int>> q;
    int melt_cnt = 0;
    q.push({x, y});
    visited[x][y] = 1;

    while (!q.empty())
    {
        pair<int, int> next = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = next.first + dx[i];
            int ny = next.second + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M)
            {
                if (!visited[nx][ny])
                {
                    visited[nx][ny] = 1;
                    if (board[nx][ny] == 0)
                    {
                        q.push({nx, ny});
                    }
                    else if (board[nx][ny] == 1)
                    {
                        board[nx][ny] = 2;
                        melt_cnt++;
                    }
                }
            }
        }
    }
    return melt_cnt;
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
        }
    }
    int bfs_cnt = 0;
    int before_melt_cnt = 0;
    int melt_cnt = 0;

    while (1)
    {
        bfs_cnt++;
        melt_cnt = bfs(N, M, 0, 0);
        if (melt_cnt == 0)
            break;
        before_melt_cnt = melt_cnt;
        board_and_visited_init(N, M);
    }
    cout << bfs_cnt - 1 << "\n";
    cout << before_melt_cnt << "\n";
}