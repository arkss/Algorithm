#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min(int a, int b){
    return a<b ? a:b;
}

int solution(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    vector<pair<int, int> > v;
    int prev = nums[0];
    int cnt = 0;
    int num;
    for (int i = 0; i < nums.size(); i++)
    {
        num = nums[i];
        if (num == prev)
            cnt++;
        else
        {
            v.push_back(make_pair(prev, cnt));
            cnt = 1;
        }
        prev = num;
    }
    v.push_back(make_pair(prev, cnt));
    return min(nums.size()/2, v.size());
}

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << solution(v) << "\n";
}