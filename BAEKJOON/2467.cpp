#include <iostream>
#include <vector>

using namespace std;

int abs(int n)
{
    if (n < 0)
        return -1 * n;
    else
        return n;
}

int main()
{
    int idxs[2];
    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    int start = 0;
    int end = N - 1;
    int zeroNearValue = 2147483647;

    while (start < end)
    {
        int nowSum = v[start] + v[end];

        if (abs(nowSum) < zeroNearValue)
        {
            idxs[0] = start;
            idxs[1] = end;

            zeroNearValue = abs(nowSum);
        }

        if (nowSum < 0)
            start++;
        else
            end--;
    }

    cout << v[idxs[0]] << " " << v[idxs[1]] << "\n";
}