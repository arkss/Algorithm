#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bottom;
vector<int> top;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, H;
    cin >> N >> H;

    bottom.resize(N / 2);
    top.resize(N / 2);

    for (int i = 0; i < N / 2; i++)
    {
        cin >> bottom[i];
        cin >> top[i];
    }

    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());

    int answer = 987654321;
    int cnt = 1;

    for (int i = 1; i <= H; i++)
    {

        int bottom_num = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
        int top_num = top.size() - (upper_bound(top.begin(), top.end(), H - i) - top.begin());

        // cout << bottom_num << " " << top_num << "\n";

        if (answer == bottom_num + top_num)
            cnt++;
        else if (answer > bottom_num + top_num)
        {
            answer = bottom_num + top_num;
            cnt = 1;
        }
    }

    cout << answer << " " << cnt << "\n";
}