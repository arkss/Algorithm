#include <iostream>
#include <vector>

using namespace std;

int board[11][11];
int visited[101];
int max_cnt[2];
int check_r[20];
int check_l[20];

void backtracking(int N, int cnt, vector<pair<int, int>> &possible, int color)
{
    max_cnt[color] = max(max_cnt[color], cnt);
    for (int i = cnt; i < possible.size(); i++)
    {
        int r = possible[i].first;
        int c = possible[i].second;

        if (board[r][c] && !check_l[c - r + N - 1] && !check_r[r + c])
        {
            check_l[c - r + N - 1] = check_r[r + c] = 1;
            backtracking(N, cnt + 1, possible, color);
            check_l[c - r + N - 1] = check_r[r + c] = 0;
        }
    }
}

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> black;
    vector<pair<int, int>> white;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j])
            {
                if ((i + j) % 2 == 0)
                    black.push_back(make_pair(i, j));
                else
                    white.push_back(make_pair(i, j));
            }
        }
    }
    backtracking(N, 0, black, 0);
    backtracking(N, 0, white, 1);

    cout << max_cnt[0] + max_cnt[1] << "\n";
}