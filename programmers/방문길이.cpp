#include <iostream>
#include <string>
#include <map>

using namespace std;

// 시작위치 5,5
int board[11][11];
// visited[x1][y1][x2][y2] : (x1, y1) -> (x2, y2)
int visited[11][11][11][11];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int solution(string dirs)
{
    map<char, int> m = {{'U', 0}, {'L', 1}, {'R', 2}, {'D', 3}};
    int answer = 0;
    int nowX = 5;
    int nowY = 5;
    for (int i = 0; i < dirs.size(); i++)
    {
        char dir = dirs[i];
        int nx = nowX + dx[m[dir]];
        int ny = nowY + dy[m[dir]];

        if (nx < 0 || 11 <= nx || ny < 0 || 11 <= ny)
            continue;

        if (!visited[nowX][nowY][nx][ny])
        {
            answer++;
            visited[nowX][nowY][nx][ny] = 1;
            visited[nx][ny][nowX][nowY] = 1;
        }

        nowX = nx;
        nowY = ny;
    }

    return answer;
}

int main()
{
    string dirs = "LULLLLLLU";
    cout << solution(dirs) << "\n";
}