#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int answer = 0;
        int A[20001];
        int B[20001];

        int N, M;
        cin >> N >> M;

        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < M; i++)
            cin >> B[i];

        sort(A, A + N);
        sort(B, B + M);

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (A[i] > B[j])
                    answer++;
                else
                    break;
            }
        }

        cout << answer << "\n";
    }
}