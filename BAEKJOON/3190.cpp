#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 뱀 : 1, 사과 : 2
int board[101][101];

// 오른, 위, 왼, 아래
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

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
    cout << "\n\n";
}

int start_game(int N, vector<pair<int, char>> infos)
{
    // start
    int x = 1, y = 1;
    board[x][y] = 1;
    // 0: 오른, 1: 위, 2: 왼, 3: 아래
    int dir = 0;
    int time = 0;

    queue<pair<int, int>> snake_pos;
    snake_pos.push({x, y});
    int snake_size = 1;

    while (1)
    {
        time++;
        x = x + dx[dir];
        y = y + dy[dir];
        // 벽에 도달 시
        if (x < 1 || x > N || y < 1 || y > N)
            break;
        // 자기 자신과 만날 시
        if (board[x][y] == 1)
            break;
        // 사과를 만날 시
        if (board[x][y] == 2)
            snake_size++;

        // snake, board 데이터 갱신
        snake_pos.push({x, y});
        board[x][y] = 1;
        while (snake_pos.size() != snake_size)
        {
            pair<int, int> pos = snake_pos.front();
            board[pos.first][pos.second] = 0;
            snake_pos.pop();
        }

        // 방향 전환
        if (infos.size() && time == infos[0].first)
        {
            if (infos[0].second == 'L')
                dir = (dir + 1) % 4;

            else if (infos[0].second == 'D')
                dir = (dir + 3) % 4;
            infos.erase(infos.begin());
        }
        // cout << time << "일 때의 board\n";
        // print_board(N);
    }

    return time;
}

int main()
{
    int N, K, L;
    cin >> N;
    cin >> K;
    vector<pair<int, char>> infos;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        board[x][y] = 2;
    }

    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int time;
        char dir;
        cin >> time >> dir;
        infos.push_back({time, dir});
    }

    int answer = start_game(N, infos);
    cout << answer << "\n";
}