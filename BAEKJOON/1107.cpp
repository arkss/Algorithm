#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int broken[10];

int min(int a, int b)
{
    return a < b ? a : b;
}

bool check(int num)
{
    string num_str = to_string(num);
    for (int i = 0; i < num_str.length(); i++)
    {
        if (broken[num_str[i] - '0'])
            return false;
    }
    return true;
}

int main()
{
    int N;
    cin >> N;

    int broken_num;
    cin >> broken_num;

    for (int i = 0; i < broken_num; i++)
    {
        int temp;
        cin >> temp;
        broken[temp] = 1;
    }

    int answer = abs(N - 100);

    for (int i = 0; i <= 1000000; i++)
    {
        if (check(i))
        {
            answer = min(answer, to_string(i).length() + abs(N - i));
        }
    }

    cout << answer << "\n";
}
