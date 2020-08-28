#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int graph[52][52];
bool is_truth[51];
vector<int> participants[51];
int visited[51];
vector<int> truth_participants;

void make_graph(int M)
{
    for (int i = 0; i < M; i++)
    {
        int party_size = participants[i].size();
        for (int j = 0; j < party_size - 1; j++)
        {
            for (int k = j + 1; k < party_size; k++)
            {
                int p1 = participants[i][j];
                int p2 = participants[i][k];

                graph[p1][p2] = 1;
                graph[p2][p1] = 1;
            }
        }
    }
}

void bfs(int start, int N)
{
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int next = 1; next <= N; next++)
        {
            if (graph[now][next])
            {
                if (!visited[next])
                {
                    visited[next] = 1;
                    is_truth[next] = true;
                    q.push(next);
                }
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    int truth_num;
    cin >> truth_num;

    for (int i = 0; i < truth_num; i++)
    {
        int num;
        cin >> num;
        truth_participants.push_back(num);
        is_truth[num] = true;
    }

    for (int i = 0; i < M; i++)
    {
        int participant_num;
        cin >> participant_num;
        for (int j = 0; j < participant_num; j++)
        {
            int num;
            cin >> num;
            participants[i].push_back(num);
        }
    }

    make_graph(M);

    for (int i = 0; i < truth_participants.size(); i++)
    {
        bfs(truth_participants[i], N);
        memset(visited, 0, sizeof(visited));
    }

    int answer = 0;
    for (int i = 0; i < M; i++)
    {
        bool is_in_truth = false;
        for (int j = 0; j < participants[i].size(); j++)
        {
            if (is_truth[participants[i][j]])
            {
                is_in_truth = true;
                break;
            }
        }
        if (!is_in_truth)
            answer++;
    }

    cout << answer << "\n";
}