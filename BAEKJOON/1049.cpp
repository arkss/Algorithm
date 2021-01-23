#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int packageMin = 1000;
    int oneMin = 1000;

    int minPrice = 0;

    for (int i = 0; i < M; i++)
    {
        int package, one;
        cin >> package >> one;

        packageMin = min(packageMin, package);
        oneMin = min(oneMin, one);
    }

    // 낱개로 사는 경우가 더 저렴할 경우
    if (packageMin > oneMin * 6)
        minPrice = N * oneMin;
    //  패키지가 더 저렴할 경우
    else
    {
        minPrice = (N / 6) * packageMin;

        int rest = N - (N / 6) * 6;

        minPrice += min(rest * oneMin, packageMin);
    }

    cout << minPrice << "\n";
}