#include <iostream>

using namespace std;

char board[51][51];

int count_max_continuous(int N)
{
    int maxCnt = 1;
    // 행으로 확인
    for (int i = 0; i < N; i++)
    {
        int continuousCnt = 1;
        char prev = board[i][0];
        for (int j = 1; j < N; j++)
        {
            if (prev == board[i][j])
                continuousCnt++;
            else
            {
                maxCnt = max(maxCnt, continuousCnt);
                continuousCnt = 1;
            }

            prev = board[i][j];
        }
        maxCnt = max(maxCnt, continuousCnt);
    }

    // 열로 확인
    for (int j = 0; j < N; j++)
    {
        int continuousCnt = 1;
        char prev = board[0][j];
        for (int i = 1; i < N; i++)
        {
            if (prev == board[i][j])
                continuousCnt++;
            else
            {
                maxCnt = max(maxCnt, continuousCnt);
                continuousCnt = 1;
            }

            prev = board[i][j];
        }
        maxCnt = max(maxCnt, continuousCnt);
    }

    return maxCnt;
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;

        for (int j = 0; j < temp.size(); j++)
        {
            board[i][j] = temp[j];
        }
    }

    int maxCnt = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            swap(&board[i][j], &board[i][j + 1]);
            maxCnt = max(maxCnt, count_max_continuous(N));
            swap(&board[i][j], &board[i][j + 1]);

            swap(&board[j][i], &board[j + 1][i]);
            maxCnt = max(maxCnt, count_max_continuous(N));
            swap(&board[j][i], &board[j + 1][i]);
        }
    }

    cout << maxCnt << "\n";
}