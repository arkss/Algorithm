#include <iostream>
#include <cstring>

using namespace std;

string dp[251];

string addStringNum(string a, string b)
{
    string rst = "";
    int maxSize = max(a.size(), b.size());

    while (a.size() < maxSize)
        a = "0" + a;

    while (b.size() < maxSize)
        b = "0" + b;

    int up = 0;
    for (int i = maxSize - 1; i >= 0; i--)
    {
        int aNum = a[i] - '0';
        int bNum = b[i] - '0';
        int tempSum = aNum + bNum + up;
        up = tempSum / 10;
        rst = to_string(tempSum % 10) + rst;
    }

    if (up)
        rst = to_string(up) + rst;

    return rst;
}

string multiplyStringNum(string a, int n)
{
    string rst = "";

    int up = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        int aNum = a[i] - '0';
        int tempRst = aNum * n + up;
        up = tempRst / 10;
        rst = to_string(tempRst % 10) + rst;
    }

    if (up)
        rst = to_string(up) + rst;

    return rst;
}

int main()
{
    dp[0] = "1";
    dp[1] = "1";
    dp[2] = "3";

    for (int i = 3; i < 251; i++)
    {
        dp[i] = addStringNum(dp[i - 1], multiplyStringNum(dp[i - 2], 2));
    }

    while (true)
    {
        int n;
        cin >> n;
        if (cin.fail() != false)
            break;

        cout << dp[n] << "\n";
    }

    return 0;
}