#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int total = 0;
    int H, W;
    cin >> H >> W;

    vector<int> v;
    v.resize(W);

    for (int i = 0; i < W; i++)
        cin >> v[i];

    for (int i = 1; i < W - 1; i++)
    {
        int leftMax = 0;
        int rightMax = 0;
        for (int j = 0; j < i; j++)
            leftMax = max(leftMax, v[j]);

        for (int j = i + 1; j < W; j++)
            rightMax = max(rightMax, v[j]);

        int minWall = min(leftMax, rightMax);
        if (minWall - v[i] > 0)
            total += minWall - v[i];
    }

    cout << total << "\n";
}