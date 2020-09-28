#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, K;
int board[10][10];
int nourishment[10][10];

vector<int> trees[10][10];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void print_trees()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << i << " " << j << "에 위치한 나무들의 나이\n";
            for (int k = 0; k < trees[i][j].size(); k++)
            {
                cout << trees[i][j][k] << " ";
            }
            cout << "\n";
        }
    }
}

void add_child_tree(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < N && 0 <= ny && ny < N)
        {
            trees[nx][ny].insert(trees[nx][ny].begin(), 1);
        }
    }
}

void spring()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < trees[i][j].size(); k++)
            {
                if (board[i][j] >= trees[i][j][k])
                {
                    board[i][j] -= trees[i][j][k];
                    trees[i][j][k]++;
                }
                else
                {
                    // summer
                    for (int l = k; l < trees[i][j].size(); l++)
                    {
                        board[i][j] += trees[i][j][l] / 2;
                    }
                    //trees[i][j].erase(0, 0);
                    trees[i][j].erase(trees[i][j].begin() + k, trees[i][j].begin() + trees[i][j].size());
                    break;
                }
            }
        }
    }
}
// void summer()
// {
// }
void autumn()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < trees[i][j].size(); k++)
            {
                if (trees[i][j][k] % 5 == 0)
                    add_child_tree(i, j);
            }
        }
    }
}
void winter()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] += nourishment[i][j];
        }
    }
}

int count_all_trees()
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cnt += (int)trees[i][j].size();
        }
    }
    return cnt;
}

void one_year()
{
    spring();
    //summer();
    autumn();
    winter();
}

int main()
{

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> nourishment[i][j];
            board[i][j] = 5;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        trees[x - 1][y - 1].push_back(z);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sort(trees[i][j].begin(), trees[i][j].end());
        }
    }

    for (int i = 0; i < K; i++)
    {
        one_year();
    }

    cout << count_all_trees() << "\n";
}