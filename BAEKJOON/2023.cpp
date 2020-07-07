#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool is_prime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void backtracking(int N, string s, int cnt)
{
    if (N == cnt)
    {
        cout << s << "\n";
    }
    else
    {
        for (int i = 1; i < 10; i++)
        {
            if (is_prime(stoi(s + to_string(i))))
            {
                s = s + to_string(i);
                backtracking(N, s, cnt + 1);
                s = s.substr(0, s.size() - 1);
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;

    backtracking(N, "", 0);
}
