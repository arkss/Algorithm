#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool end_flag;

bool check_good_array(string answer, char num)
{
    answer = answer + num;
    int len = 1;

    while (1)
    {
        if (int(answer.size()) - len - len < 0)
            break;
        string s1 = answer.substr(answer.size() - len, len);
        string s2 = answer.substr(answer.size() - len - len, len);
        if (s1 == s2)
            return false;
        len++;
    }
    return true;
}

void backtracking(string answer, vector<char> nums, int cnt, int N)
{
    if (end_flag)
        return;

    if (N == cnt)
    {
        cout << answer << "\n";
        end_flag = 1;
        return;
    }

    else
        for (int i = 0; i < nums.size(); i++)
        {
            if (check_good_array(answer, nums[i]))
            {
                answer += nums[i];
                backtracking(answer, nums, cnt + 1, N);
                answer = answer.substr(0, answer.size() - 1);
            }
        }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<char> nums = {'1', '2', '3'};

    backtracking("1", nums, 1, N);
}