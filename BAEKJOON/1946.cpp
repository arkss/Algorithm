#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0); //실행속도 향상

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;

        vector<pair<int, int>> v;

        for (int i = 0; i < N; i++)
        {
            int document, interview;
            cin >> document >> interview;

            v.push_back({document, interview});
        }
        sort(v.begin(), v.end());

        int passCnt = 1;
        int interview_first = v[0].second;

        for (int i = 1; i < N; i++)
        {

            if (v[i].second < interview_first)
            {
                interview_first = v[i].second;
                passCnt++;
            }
        }

        cout << passCnt << "\n";
    }
}