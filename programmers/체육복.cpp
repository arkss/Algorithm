#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    // student[i] 는 보유한 체육복의 수
    int student[32];

    for (int i = 1; i <= n; i++)
        student[i] = 1;
    for (int i : lost)
        student[i]--;
    for (int i : reserve)
        student[i]++;
    for (int i = 1; i <= n; i++)
    {
        if (student[i] == 0)
        {
            if (student[i - 1] == 2)
            {
                student[i - 1]--;
                student[i]++;
            }
            else if (student[i + 1] == 2)
            {
                student[i + 1]--;
                student[i]++;
            }
        }
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (student[i] > 0)
            cnt++;
    }
    return cnt;
}

int main()
{
    int n = 7;
    vector<int> lost;
    vector<int> reserve;

    lost.push_back(2);
    lost.push_back(3);
    lost.push_back(4);

    reserve.push_back(1);
    reserve.push_back(2);
    reserve.push_back(3);
    reserve.push_back(6);

    cout << solution(n, lost, reserve) << "\n";

    return 0;
}
