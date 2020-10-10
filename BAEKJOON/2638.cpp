#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
// 0: 공기, 1: 치즈, 2이상의 수: 1+외부 면적과 닿아있는 부분
int board[101][101];
int visited[101][101];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void print_board()
{
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

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if (!(0 <= nx && nx < N && 0 <= ny && ny < M))
                continue;

            if (board[nx][ny] > 0)
                board[nx][ny]++;

            if (visited[nx][ny])
                continue;

            if (board[nx][ny] == 0)
            {
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }
}

void melt_cheese()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] > 2)
                board[i][j] = 0;
            else if (board[i][j] == 2)
                board[i][j] = 1;
        }
    }
}

bool check_all_melt()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] != 0)
                return false;
        }
    }
    return true;
}

int main()
{

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    int answer = 0;
    while (1)
    {
        bfs(0, 0);
        melt_cheese();
        //print_board();
        answer++;
        bool is_end = check_all_melt();
        if (is_end)
            break;
        memset(visited, 0, sizeof(visited));
    }
    cout << answer << "\n";
}