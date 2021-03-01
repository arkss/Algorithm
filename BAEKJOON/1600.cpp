#include <iostream>
#include <queue>

using namespace std;

int board[201][201];
// visited[x][y][z]: x,y에 z번의 나이트 움직임으로 온 적이 있는가
int visited[201][201][31];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int hdx[] = {-2, -2, 2, 2, -1, 1, -1, 1};
int hdy[] = {-1, 1, -1, 1, -2, -2, 2, 2};

int K;
int W, H;

void print_visited()
{
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}

int bfs(int x, int y)
{
    // {{x,y}, {나이트 움직임 사용 수, 이동 수}}
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{x, y}, {0, 0}});
    visited[x][y][0] = 1;

    while (!q.empty())
    {
        pair<pair<int, int>, pair<int, int>> now = q.front();
        int nowX = now.first.first;
        int nowY = now.first.second;
        int nowNightCnt = now.second.first;
        int moveCnt = now.second.second;
        q.pop();

        if (nowX == H - 1 && nowY == W - 1)
            return moveCnt;

        if (nowNightCnt < K)
        {
            for (int i = 0; i < 8; i++)
            {
                int nx = nowX + hdx[i];
                int ny = nowY + hdy[i];

                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                    continue;

                if (board[nx][ny])
                    continue;

                if (visited[nx][ny][nowNightCnt + 1])
                    continue;

                visited[nx][ny][nowNightCnt + 1] = 1;
                q.push({{nx, ny}, {nowNightCnt + 1, moveCnt + 1}});
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = nowX + dx[i];
            int ny = nowY + dy[i];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;

            if (board[nx][ny])
                continue;

            if (visited[nx][ny][nowNightCnt])
                continue;

            visited[nx][ny][nowNightCnt] = 1;
            q.push({{nx, ny}, {nowNightCnt, moveCnt + 1}});
        }
    }

    return -1;
}

int main()
{
    cin >> K;
    cin >> W >> H;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> board[i][j];

    int moveCnt = bfs(0, 0);
    cout << moveCnt << "\n";

    return 0;
}