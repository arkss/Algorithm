#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    long long temp = 0;
    while (n != 0)
    {
        temp = temp * 10 + n % 3;
        n /= 3;
    }

    int answer = 0;
    int pos = 1;
    while (temp != 0)
    {
        answer += (temp % 10) * pos;
        pos *= 3;
        temp /= 10;
    }

    return answer;
}

int main()
{
    cout << solution(45) << "\n";
}