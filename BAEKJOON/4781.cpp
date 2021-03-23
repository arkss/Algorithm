#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> //memset

using namespace std;

int dp[10002];

int double_to_int(string str)
{
    return stoi(str.erase(str.find('.'), 1));
}

int main()
{
    while (1)
    {
        memset(dp, 0, sizeof(dp));
        int n, totalPrice;
        string temp;
        cin >> n >> temp;
        totalPrice = double_to_int(temp);

        if (n == 0 && totalPrice == 0)
            break;

        vector<pair<int, int>> candys;
        for (int i = 0; i < n; i++)
        {
            int price, calorie;
            string temp;
            cin >> calorie >> temp;
            price = double_to_int(temp);

            candys.push_back({price, calorie});
        }

        for (int i = 0; i < n; i++)
        {
            int price = candys[i].first;
            int calorie = candys[i].second;

            for (int j = 1; j <= totalPrice + 1; j++)
            {
                if (j - price >= 0)
                    dp[j] = max(dp[j], dp[j - price] + calorie);
            }
        }

        cout << dp[totalPrice] << "\n";
    }
}