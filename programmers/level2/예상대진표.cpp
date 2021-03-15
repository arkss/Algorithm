#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    int p1 = min(a, b);
    int p2 = max(a, b);

    while (1)
    {
        if (p1 % 2 == 1 && p2 - p1 == 1)
            break;

        p1 = (p1 + 1) / 2;
        p2 = (p2 + 1) / 2;
        answer++;
    }

    return answer;
}

int main()
{
    cout << solution(8, 1, 2) << "\n";
    cout << solution(8, 2, 3) << "\n";
    cout << solution(8, 2, 5) << "\n";
    cout << solution(8, 4, 6) << "\n";
    cout << solution(8, 4, 7) << "\n";
}