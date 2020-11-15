#include <iostream>
#include <queue>

using namespace std;

// 1: 익은 토마토, 0: 익지않은 토마토, -1: 토마토가 없는 칸
int board[102][102][102];
int M, N, H;
//  위, 아래, 왼쪽, 오른쪽, 앞, 뒤
int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, -1, 1, 0, 0};
int dh[] = {-1, 1, 0, 0, 0, 0};

struct POS
{
    int x, y, h;
};

int main()
{
    cin >> M >> N >> H;
    int answer = 0;
    queue<pair<POS, int>> q;

    for (int h = 0; h < H; h++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> board[i][j][h];
                if (board[i][j][h] == 1)
                    q.push({{i, j, h}, 0});
            }
        }
    }

    while (!q.empty())
    {
        pair<POS, int> now = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nx = now.first.x + dx[i];
            int ny = now.first.y + dy[i];
            int nh = now.first.h + dh[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && 0 <= nh && nh < H)
            {
                if (board[nx][ny][nh] == 0)
                {
                    board[nx][ny][nh] = 1;
                    q.push({{nx, ny, nh}, now.second + 1});
                    answer = now.second + 1;
                }
            }
        }
    }

    for (int h = 0; h < H; h++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {

                if (board[i][j][h] == 0)
                {
                    cout << -1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << answer << "\n";
}
