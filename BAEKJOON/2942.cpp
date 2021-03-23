#include <iostream>

using namespace std;

int calcurate_gcd(int a, int b)
{
    if (b > a)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    while (1)
    {
        int temp = b;
        b = a % b;
        a = temp;

        if (b == 0)
            break;
    }
    return a;
}

int main()
{
    int R, G;
    cin >> R >> G;

    int gcd = calcurate_gcd(R, G);

    for (int i = 1; i <= gcd; i++)
        if (gcd % i == 0)
            cout << i << " " << R / i << " " << G / i << "\n";
}