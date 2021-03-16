#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[1001][1001];
int dx[] = {1, 0, -1};
int dy[] = {0, 1, -1};

void print_arr(int n)
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

vector<int> solution(int n)
{
    int moveCnt = n;
    int dir = 0;

    int x = 0;
    int y = 0;
    int nowMoveCnt = moveCnt - 1;

    for (int i = 1; i <= n * (n + 1) / 2; i++)
    {
        arr[x][y] = i;
        x = x + dx[dir];
        y = y + dy[dir];
        nowMoveCnt--;
        if (nowMoveCnt == 0)
        {
            dir = (dir + 1) % 3;
            nowMoveCnt = --moveCnt;
        }
    }

    //print_arr(n);
    vector<int> answer;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
            answer.push_back(arr[i][j]);
    }

    return answer;
}

int main()
{
    solution(6);
}