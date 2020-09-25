#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;
// +, -, x, /
int oper[4];
vector<int> opers;
int visited[11];
int max_result = -100000000, min_result = 100000000;

void backtracking(int N, int cnt, int sub_result)
{
    if (N == cnt)
    {

        max_result = max(max_result, sub_result);
        min_result = min(min_result, sub_result);
    }
    else
    {
        for (int i = 0; i < opers.size(); i++)
        {
            int temp;
            if (!visited[i])
            {
                visited[i] = 1;
                switch (opers[i])
                {
                case 0:
                    temp = sub_result + nums[cnt];
                    break;
                case 1:
                    temp = sub_result - nums[cnt];
                    break;
                case 2:
                    temp = sub_result * nums[cnt];
                    break;
                case 3:
                    temp = sub_result / nums[cnt];
                    break;
                }

                backtracking(N, cnt + 1, temp);
                visited[i] = 0;
            }
        }
    }
}

void print_opers()
{
    for (int i = 0; i < opers.size(); i++)
    {
        cout << opers[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    for (int i = 0; i < 4; i++)
        cin >> oper[i];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < oper[i]; j++)
        {
            opers.push_back(i);
        }
    }

    backtracking(N, 1, nums[0]);

    cout << max_result << "\n"
         << min_result;
}