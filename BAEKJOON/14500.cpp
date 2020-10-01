#include <iostream>

using namespace std;

int board[501][501];
int N, M;
int visited[6];
int answer;

void backtracking(int x, int y, int cnt, int type)
{
    if (cnt == 2)
    {
        if (visited[2] && visited[3])
            return;
        if (visited[0] && visited[3])
            return;
        if (visited[1] && visited[2])
            return;
        if (visited[2] && visited[5])
            return;
        if (visited[3] && visited[4])
            return;
        int six_board[6];
        if (type == 0)
        {
            six_board[0] = board[x][y];
            six_board[1] = board[x][y + 1];
            six_board[2] = board[x + 1][y];
            six_board[3] = board[x + 1][y + 1];
            six_board[4] = board[x + 2][y];
            six_board[5] = board[x + 2][y + 1];
        }

        else if (type == 1)
        {
            six_board[0] = board[x][y];
            six_board[1] = board[x + 1][y];
            six_board[2] = board[x][y + 1];
            six_board[3] = board[x + 1][y + 1];
            six_board[4] = board[x][y + 2];
            six_board[5] = board[x + 1][y + 2];
        }

        int temp = 0;
        for (int i = 0; i < 6; i++)
        {
            if (!visited[i])
                temp += six_board[i];
        }

        answer = max(answer, temp);
        return;
    }

    for (int i = 0; i < 6; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            backtracking(x, y, cnt + 1, type);
            visited[i] = 0;
        }
    }
}

int calculate_skyblue()
{
    int max_value = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M - 3; j++)
        {
            int temp = 0;
            for (int k = 0; k < 4; k++)
            {
                temp += board[i][j + k];
            }
            max_value = max(max_value, temp);
        }
    }

    for (int i = 0; i < N - 3; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int temp = 0;
            for (int k = 0; k < 4; k++)
            {
                temp += board[i + k][j];
            }
            max_value = max(max_value, temp);
        }
    }

    return max_value;
}

void calculate_six_block()
{
    /*
    ##
    ##
    ## 중에서 2개 제거
    */
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = 0; j < M - 1; j++)
        {

            backtracking(i, j, 0, 0);
        }
    }

    /*
    ###
    ### 중에서 2개 제거
    */

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < M - 2; j++)
        {

            backtracking(i, j, 0, 1);
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    answer = 0;

    // case1 하늘색
    answer = max(answer, calculate_skyblue());
    // case2 나머지
    calculate_six_block();

    cout << answer << "\n";
}