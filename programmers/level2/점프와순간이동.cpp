#include <iostream>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 1;
    while (n != 1)
    {
        if (n % 2 != 0)
        {
            answer++;
            n--;
        }
        else
            n /= 2;
    }

    return answer;
}
