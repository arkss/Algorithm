#include <iostream>

using namespace std;

int board[10][10];
int visited[10][10];
int N;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

pair<int, int> int_to_point(int p)
{
    pair<int, int> point;
    point.first = p / N;
    point.second = p % N;
    return point;
}

int calcurate_land_price(int p1, int p2, int p3)
{
    int priceSum = 0;
    pair<int, int> points[3];
    points[0] = int_to_point(p1);
    points[1] = int_to_point(p2);
    points[2] = int_to_point(p3);

    for (int i = 0; i < 3; i++)
    {
        if (points[i].first == 0 || points[i].second == 0)
            return 3001;
        if (points[i].first == N - 1 || points[i].second == N - 1)
            return 3001;
    }

    for (int i = 0; i < 3; i++)
    {
        int nx = points[i].first;
        int ny = points[i].second;

        if (visited[nx][ny])
            return 3001;
        visited[nx][ny] = 1;
        priceSum += board[nx][ny];

        for (int j = 0; j < 4; j++)
        {
            int nnx = nx + dx[j];
            int nny = ny + dy[j];

            if (visited[nnx][nny])
                return 3001;
            visited[nnx][nny] = 1;
            priceSum += board[nnx][nny];
        }
    }

    return priceSum;
}

void init_visited()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            visited[i][j] = 0;
}

int main()
{
    int rst = 3001;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    for (int i = 0; i < N * N; i++)
        for (int j = i + 1; j < N * N; j++)
            for (int k = j + 1; k < N * N; k++)
            {
                init_visited();
                rst = min(rst, calcurate_land_price(i, j, k));
            }

    cout << rst << "\n";
}