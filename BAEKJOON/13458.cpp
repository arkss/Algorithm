#include <iostream>

using namespace std;

int A[1000000];

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int B, C;
    cin >> B >> C;

    long supervisor_num = 0;

    for (int i = 0; i < N; i++)
    {
        if (A[i] == 0)
            continue;
        A[i] -= B;
        if (A[i] < 0)
            A[i] = 0;
        supervisor_num++;

        if (A[i] == 0)
            continue;

        supervisor_num += A[i] / C;
        if (A[i] % C)
            supervisor_num++;
    }

    cout << supervisor_num << "\n";
}