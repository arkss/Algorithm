#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int board[202][202];
int rboard[202][202];
int N, M;

int visited[202];

void print_board(int isR)
{

    cout << "\n\n";
    if (isR)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cout << rboard[i][j] << " ";
            }
            cout << "\n";
        }
    }

    else
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }

    cout << "\n\n";
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 1; i <= N; i++)
        {
            if (!visited[i] && board[now][i])
            {
                visited[i] = 1;
                q.push(i);
                rboard[s][i] = 1;
                rboard[i][s] = 1;
            }
        }
    }
}

void calculate_graph()
{
    for (int i = 1; i <= N; i++)
    {
        //cout << i << "번째 bfs\n";
        memset(visited, 0, sizeof(visited));
        bfs(i);
    }
}

int main()
{

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                rboard[i][j] = 1;
            cin >> board[i][j];
        }
    }
    calculate_graph();
    //print_board(1);

    vector<int> cities;

    for (int i = 0; i < M; i++)
    {
        int city;
        cin >> city;
        cities.push_back(city);
    }

    for (int i = 0; i < M - 1; i++)
    {
        if (!rboard[cities[i]][cities[i + 1]])
        {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
}