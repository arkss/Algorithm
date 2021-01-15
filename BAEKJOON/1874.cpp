#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;

    bool is_possible = true;

    vector<int> v;
    vector<char> rst;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    int num = 1;

    for (int i = 0; i < n; i++)
    {
        int goal = v[i];
        // cout << "goal : " << goal << "\n";
        // cout << "num : " << num << "\n";

        if (goal == num)
        {
            num++;
            rst.push_back('+');
            rst.push_back('-');
        }

        else if (goal > num)
        {
            int diff = goal - num;
            for (int j = 0; j <= diff; j++)
            {
                s.push(num++);
                rst.push_back('+');
            }
            s.pop();
            rst.push_back('-');
        }

        else
        {
            if (s.top() == goal)
            {
                s.pop();
                rst.push_back('-');
            }
            else
            {
                is_possible = false;
                break;
            }
        }

        // cout << "rst\n";
        // for (int i = 0; i < rst.size(); i++)
        // {
        //     cout << rst[i] << " ";
        // }
        // cout << "\n\n";
    }

    if (is_possible)
    {
        for (int i = 0; i < rst.size(); i++)
        {
            cout << rst[i] << "\n";
        }
    }

    else
        cout << "NO\n";
}
