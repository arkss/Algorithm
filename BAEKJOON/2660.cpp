#include <iostream>

using namespace std;

#define INF 987654321

int graph[51][51];
int points[51];

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    while (1)
    {
        int f1, f2;
        cin >> f1 >> f2;

        if (f1 == -1 && f2 == -1)
            break;

        graph[f1][f2] = 1;
        graph[f2][f1] = 1;
    }

    for (int mid = 1; mid <= N; mid++)
    {
        for (int start = 1; start <= N; start++)
        {
            for (int end = 1; end <= N; end++)
            {
                if (graph[start][end] > graph[start][mid] + graph[mid][end])
                {
                    // 더 가까운 경로가 있을 경우 최신화
                    graph[start][end] = graph[start][mid] + graph[mid][end];
                }
            }
        }
    }

    int minPoint = INF;
    int minPointCnt = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            points[i] = max(points[i], graph[i][j]);
        }

        if (minPoint > points[i])
        {
            minPoint = points[i];
            minPointCnt = 1;
        }
        else if (minPoint == points[i])
        {
            minPointCnt++;
        }
    }

    cout << minPoint << " " << minPointCnt << "\n";
    for (int i = 1; i <= N; i++)
    {
        if (minPoint == points[i])
            cout << i << " ";
    }
}