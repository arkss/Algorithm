#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int N;
// 동 서 남 북
double percentage[4];
double answer;

bool visited[30][30];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

double calcurate_percentage(vector<int> v)
{
    double rst = 1;
    for (int i = 0; i < v.size(); i++)
    {
        rst *= (percentage[v[i]]);
    }

    return rst;
}

void backtracking(int cnt, int x, int y, vector<int> dirs)
{
    if (cnt == N)
        answer += calcurate_percentage(dirs);
    else
    {
        visited[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!visited[nx][ny])
            {
                visited[nx][ny] = true;
                dirs.push_back(i);
                backtracking(cnt + 1, nx, ny, dirs);
                dirs.pop_back();
                visited[nx][ny] = false;
            }
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < 4; i++)
    {
        int per;
        cin >> per;
        percentage[i] = per * 0.01;
    }

    vector<int> dirs;

    backtracking(0, 15, 15, dirs);

    cout << fixed;
    cout << setprecision(10) << answer << "\n";
}