#include <iostream>
#include <vector>

using namespace std;

int board[1001][1001];
vector<pair<int, int>> adjust[1001];
#define INF 987654321

void floyd_warshall(int N)
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (board[i][j] == 0 && i != j)
                board[i][j] = INF;

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
}

void print_board(int N)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    int N, M, X;
    cin >> N >> M >> X;

    for (int i = 0; i < M; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        board[start][end] = weight;
        //adjust[start].push_back({end, weight});
    }

    floyd_warshall(N);

    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        answer = max(answer, board[X][i] + board[i][X]);
    }
    cout << answer << "\n";
}