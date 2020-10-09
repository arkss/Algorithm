#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int board[22][22];
int N;
int areas[5];

// 기준점 (x, y)와 경계의 길이 d1, d2를 정한다. (d1, d2 ≥ 1, 1 <= x < x+d1+d2 <= N, 1 <= y-d1 < y < y+d2 <= N)

/*
1번 선거구: 1 <= r < x+d1, 1 <= c <= y
2번 선거구: 1 <= r <= x+d2, y < c <= N
3번 선거구: x+d1 <= r <= N, 1 <= c < y-d1+d2
4번 선거구: x+d2 < r <= N, y-d1+d2 <= c <= N
*/

bool is_valid(int x, int y, int d1, int d2)
{
    return (x < x + d1 + d2 && x + d1 + d2 <= N && 1 <= y - d1 && y - d1 < y + d2 && y + d2 <= N);
}

int calcurate_areas(int x, int y, int d1, int d2)
{
    for (int r = 1; r <= N; r++)
    {
        for (int c = 1; c <= N; c++)
        {
            // 1
            if (r < x + d1 && c <= y && !(r >= x && c >= y - (r - x)))
                areas[0] += board[r][c];

            // 2
            else if (r <= x + d2 && y < c && !(r >= x && c <= y + (r - x)))
                areas[1] += board[r][c];
            // 3
            else if (x + d1 <= r && c < y - d1 + d2 && !(r <= x + d1 + d2 && c >= (y - d1 + d2 - (x + d1 + d2 - r))))
                areas[2] += board[r][c];
            // 4
            else if (x + d2 < r && y - d1 + d2 <= c && !(r <= x + d1 + d2 && c <= (y - d1 + d2 + (x + d1 + d2 - r))))
                areas[3] += board[r][c];
            else
                areas[4] += board[r][c];
        }
    }

    int max_area = 0;
    int min_area = 987654321;

    for (int i = 0; i < 5; i++)
    {
        max_area = max(max_area, areas[i]);
        min_area = min(min_area, areas[i]);
    }

    return max_area - min_area;
}

int main()
{
    int answer = 987654321;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int x = 1; x < N; x++)
    {
        for (int y = 1; y < N; y++)
        {
            for (int d1 = 1; d1 < N; d1++)
            {
                for (int d2 = 1; d2 < N; d2++)
                {
                    if (is_valid(x, y, d1, d2))
                    {

                        answer = min(answer, calcurate_areas(x, y, d1, d2));

                        memset(areas, 0, sizeof(areas));
                        // cout << x << " " << y << " " << d1 << " " << d2 << "\n";
                        // cout << calcurate_areas(x, y, d1, d2) << "\n";
                        // for (int i = 0; i < 5; i++)
                        // {
                        //     cout << areas[i] << " ";
                        // }
                        // cout << "\n";
                        memset(areas, 0, sizeof(areas));
                    }
                }
            }
        }
    }

    cout << answer << "\n";
}