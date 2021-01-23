#include <iostream>

using namespace std;

int main()
{
    double X, Y;
    cin >> X >> Y;

    int Z = (Y * 100) / X;

    if (Z >= 99)
    {
        cout << "-1\n";
        return 0;
    }

    int start = 0;
    int end = X;

    int result = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        int tempZ = ((Y + mid) * 100) / (X + mid);

        if (Z >= tempZ)
        {
            result = mid + 1;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    cout << result << "\n";
}
