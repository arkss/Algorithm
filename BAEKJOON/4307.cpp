#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int length, n;
        cin >> length >> n;

        int minTime = 0;
        int maxTime = 0;

        for (int i = 0; i < n; i++)
        {
            int pos;
            cin >> pos;

            if (pos > length / 2)
                minTime = max(minTime, length - pos);
            else
                minTime = max(minTime, pos);

            maxTime = max(maxTime, length - pos);
            maxTime = max(maxTime, pos);
        }

        cout << minTime << " " << maxTime << "\n";
    }
}