#include <iostream>
#include <cmath>

using namespace std;

double calculate_dis(int x1, int y1, int x2, int y2)
{
    return pow((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2), 0.5);
}

int abs(int n)
{
    return n > 0 ? n : n * (-1);
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int pos_cnt;
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        if (x1 == x2 && y1 == y2 && r1 == r2)
        {
            cout << -1 << "\n";
            continue;
        }

        double distance = calculate_dis(x1, y1, x2, y2);
        if (r1 + r2 < distance || distance < abs(r1 - r2))
            pos_cnt = 0;
        else if (r1 + r2 == distance || distance == abs(r1 - r2))
            pos_cnt = 1;
        else if (r1 + r2 > distance || distance > abs(r1 - r2))
            pos_cnt = 2;

        cout << pos_cnt << "\n";
    }
}