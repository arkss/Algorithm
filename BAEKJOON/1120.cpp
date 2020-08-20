#include <iostream>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int max_matching_cnt = 0;
    for (int i = 0; i < s2.size() - s1.size() + 1; i++)
    {
        int cnt = 0;
        int sidx = i;
        for (int j = 0; j < s1.size(); j++)
        {
            if (s1[j] == s2[sidx++])
                cnt++;
        }
        max_matching_cnt = max(max_matching_cnt, cnt);
    }

    cout << s1.size() - max_matching_cnt << "\n";
}