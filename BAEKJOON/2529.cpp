#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> signs;
vector<string> answer;

bool visited[10];

bool checkValidSign(vector<int> nums)
{
    for (int i = 0; i < signs.size(); i++)
    {
        if (signs[i] == "<" && (nums[i] > nums[i + 1]))
            return false;
        else if (signs[i] == ">" && (nums[i] < nums[i + 1]))
            return false;
    }
    return true;
}

void backtracking(int goal, int cnt, vector<int> nums)
{
    if (goal == cnt)
    {
        if (checkValidSign(nums))
        {
            string rst = "";
            for (int i = 0; i < nums.size(); i++)
                rst += to_string(nums[i]);

            answer.push_back(rst);
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                nums.push_back(i);
                backtracking(goal, cnt + 1, nums);
                nums.pop_back();
                visited[i] = false;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        signs.push_back(temp);
    }

    vector<int> nums;
    backtracking(n + 1, 0, nums);

    cout << answer[answer.size() - 1] << "\n";
    cout << answer[0] << "\n";
}