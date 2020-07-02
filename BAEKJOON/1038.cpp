#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;
    if (N < 10)
        cout << N << "\n";
    else if (N == 1022)
        cout << 9876543210 << "\n";
    else if (N >= 1023)
        cout << -1 << "\n";
    else
    {
        queue<int> q;
        int cnt = 0;
        for (int i = 1; i < 10; i++)
        {
            q.push(i);
            cnt++;
        }
        while (N > cnt)
        {
            int i, tmp;
            i = q.front();
            q.pop();

            tmp = i % 10;
            for (int j = 0; j < tmp; j++)
            {
                q.push(10 * i + j);
                cnt++;
                if (N == cnt)
                {
                    cout << q.back() << "\n";
                    break;
                }
            }
        }
    }
}