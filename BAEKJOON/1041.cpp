#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    long long answer = 0;
    int dices[6];
    int min1 = 51;
    int min2 = 51 * 2;
    int min3 = 51 * 3;

    for (int i = 0; i < 6; i++)
    {
        cin >> dices[i];
        if (dices[i] < min1)
            min1 = dices[i];
    }

    if (N == 1)
    {
        sort(dices, dices + 6);
        for (int i = 0; i < 5; i++)
            answer += dices[i];

        cout << answer << "\n";
        return 0;
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            if ((i == 0 && j == 5) || (i == 2 && j == 3) || (i == 1 && j == 4))
                continue;
            min2 = min(min2, dices[i] + dices[j]);
        }
    }

    min3 = min(min3, dices[0] + dices[1] + dices[2]);
    min3 = min(min3, dices[0] + dices[1] + dices[3]);
    min3 = min(min3, dices[1] + dices[3] + dices[5]);
    min3 = min(min3, dices[1] + dices[2] + dices[5]);
    min3 = min(min3, dices[2] + dices[4] + dices[5]);
    min3 = min(min3, dices[3] + dices[4] + dices[5]);
    min3 = min(min3, dices[0] + dices[3] + dices[4]);
    min3 = min(min3, dices[0] + dices[2] + dices[4]);

    answer += min1 * (1LL * N * N * 5 - ((N - 1) * 4 + (N - 2) * 4) * 2 - 4 * 3);
    answer += min2 * (1LL * ((N - 1) * 4 + (N - 2) * 4));
    answer += min3 * 4;

    cout << answer << "\n";
}

/*
맨 위에 주사위 위들을 제외하고는 그냥 최소값으로 선택가능
N^3개 주사위 사용시, 5*N^2개의 면

*/