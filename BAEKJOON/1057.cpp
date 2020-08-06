/*
시간초과
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // p1 < p2
    int N, p1, p2;
    cin >> N >> p1 >> p2;

    queue<pair<int, int>> q;
    for (int i = 1; i <= N; i++)
        q.push({i, 1});

    int round_num;
    while (1)
    {
        pair<int, int> a = q.front();
        q.pop();
        pair<int, int> b = q.front();
       //cout << a.first << " " << b.first << "의 배틀\n";

        // 둘의 라운드 번호가 다르면
        if (a.second != b.second)
        {
            a.second++;
            q.push(a);
        }
        // 둘의 라운드 번호가 같으면
        else
        {
            // 지민 vs 한수
            if (a.first == p1 && b.first == p2)
            {
                round_num = a.second;
                break;
            }
            // 지민
            else if (a.first == p1 || a.first == p2)
            {
                a.second++;
                q.push(a);
            }

            // 한수
            else
            {
                b.second++;
                q.push(b);
            }
            q.pop();
        }
    }
    cout << round_num << "\n";
}
*/

#include <iostream>

using namespace std;

int go_next_round(int n)
{
    if (n % 2 == 0)
        return n / 2;
    else
        return (n + 1) / 2;
}

int main()
{
    int N, p1, p2;
    cin >> N >> p1 >> p2;

    int round_num = 1;
    while (1)
    {
        if ((p1 + 1) / 2 == (p2 + 1) / 2)
            break;
        p1 = go_next_round(p1);
        p2 = go_next_round(p2);
        round_num++;
    }

    cout << round_num << "\n";
}
