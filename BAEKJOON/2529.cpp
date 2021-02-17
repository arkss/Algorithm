#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
vector<string> signs;
vector<int> answer;

bool visited[10];

vector<string> split(string input, char delimiter)
{
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter))
    {
        answer.push_back(temp);
    }

    return answer;
}

bool checkValidSign(vector<int> nums)
{
    for (int i = 0; i < signs.size(); i++)
    {
        if (signs[i] == "<" && nums[i] > nums[i + 1])
            return false;
        else if (signs[i] == "<" && nums[i] < nums[i + 1])
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
            for (int i = 0; i < nums.size(); i++)
            {
                cout << nums[i] << " ";
            }
            cout << "\n";
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

    string strSigns;
    cin >> strSigns;

    signs = split(strSigns, ' ');
    vector<int> nums;
    backtracking(n + 1, 0, nums);
}