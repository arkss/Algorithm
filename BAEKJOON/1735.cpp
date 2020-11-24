#include <iostream>

using namespace std;

int gcd(int n, int m)
{
    if (m > n)
    {
        int temp = m;
        m = n;
        n = temp;
    }

    while (1)
    {
        int temp = m;
        m = n % m;
        n = temp;

        if (m == 0)
            return n;
    }
}

int lcd(int n, int m)
{
    return (n * m) / gcd(n, m);
}

int main()
{
    int a1, a2;
    int b1, b2;
    int s1, s2;

    cin >> a1 >> a2;
    cin >> b1 >> b2;

    s2 = lcd(a2, b2);
    s1 = (s2 / a2) * a1 + (s2 / b2) * b1;

    int s_gcd = gcd(s1, s2);
    s1 = s1 / s_gcd;
    s2 = s2 / s_gcd;

    cout << s1 << " " << s2 << "\n";
}