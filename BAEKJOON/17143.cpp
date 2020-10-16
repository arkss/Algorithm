#include <iostream>
#include <vector>

using namespace std;

struct SHARK
{
    int x, y;
    int speed;
    int dir;
    int size;
    bool is_alive;
};

vector<SHARK> sharks;
int board[101][101];
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};
int R, C, M;
int answer;

int main()
{
    sharks.push_back({-1, -1, -1, -1, -1, false});
    cin >> R >> C >> M;
    for (int i = 1; i <= M; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        r--;
        c--;
        sharks.push_back({r, c, s, d, z, true});
        board[r][c] = i;
    }

    for (int j = 0; j < C; j++)
    {
        // 상어 낚시
        for (int i = 0; i < R; i++)
        {
            if (board[i][j])
            {
                sharks[board[i][j]].is_alive = false;
                answer += sharks[board[i][j]].size;
                board[i][j] = 0;
                break;
            }
        }

        int temp_board[101][101] = {0};

        // 상어 이동
        for (int i = 1; i <= M; i++)
        {
            if (!sharks[i].is_alive)
                continue;
            int x = sharks[i].x;
            int y = sharks[i].y;
            int speed = sharks[i].speed;
            int dir = sharks[i].dir;
            int size = sharks[i].size;
            int nx, ny;

            while (1)
            {
                nx = x + speed * dx[dir];
                ny = y + speed * dy[dir];
                if (0 <= nx && nx < R && 0 <= ny && ny < C)
                    break;

                if (dir == 1 && nx < 0)
                {
                    speed -= x;
                    x = 0;
                    dir = 2;
                }
                else if (dir == 2 && nx >= R)
                {
                    speed -= R - 1 - x;
                    x = R - 1;
                    dir = 1;
                }
                else if (dir == 3 && ny >= C)
                {
                    speed -= C - 1 - y;
                    y = C - 1;
                    dir = 4;
                }
                else if (dir == 4 && ny < 0)
                {
                    speed -= y;
                    y = 0;
                    dir = 3;
                }
            }

            if (temp_board[nx][ny])
            {
                // 새로 이동해온 물고기가 더 큼
                if (sharks[temp_board[nx][ny]].size < size)
                {
                    sharks[temp_board[nx][ny]].is_alive = false;
                    temp_board[nx][ny] = i;
                }
                else
                {
                    sharks[i].is_alive = false;
                }
            }
            else
                temp_board[nx][ny] = i;

            sharks[i].x = nx;
            sharks[i].y = ny;
            sharks[i].dir = dir;
        }

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                board[i][j] = temp_board[i][j];
            }
        }
    }

    cout << answer << "\n";
}
