#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int arr[100001];

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int start = 0;
    int end = N - 1;

    int ans_s = 0;
    int ans_e = N - 1;

    while (start < end)
    {
        if (abs(arr[start] + arr[end]) < abs(arr[ans_s] + arr[ans_e]))
        {
            ans_s = start;
            ans_e = end;
        }

        if (arr[start] + arr[end] > 0)
            end--;
        else
            start++;
    }

    cout << arr[ans_s] << " " << arr[ans_e] << "\n";
}