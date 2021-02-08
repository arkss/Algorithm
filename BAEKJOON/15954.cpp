#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<long double> preferences;

long double calculate_average(int start, int end)
{
    long long sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum += preferences[i];
    }
    return sum / (long double)(end - start + 1);
}

long double calculate_standard_deviation(int start, int end)
{
    long double standardDeviationSum = 0;
    long double average = calculate_average(start, end);

    for (int i = start; i <= end; i++)
    {
        standardDeviationSum += (preferences[i] - average) * (preferences[i] - average);
    }
    return sqrt(standardDeviationSum / (long double)(end - start + 1));
}

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        long double preference;
        cin >> preference;

        preferences.push_back(preference);
    }

    // sort(preferences.begin(), preferences.end());

    long double standardDeviation = 987654321.0f;

    for (int m = M; m <= N; m++)
        for (int i = 0; i < N - m + 1; i++)
        {
            long double rst = calculate_standard_deviation(i, i + m - 1);
            standardDeviation = min(standardDeviation, rst);
        }

    cout.precision(11);
    cout << standardDeviation;
}
