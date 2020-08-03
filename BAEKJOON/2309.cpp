#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int visited[9];
bool end_flag = false;

void print_vector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n\n";
}

void backtracking(int cnt, vector<int> dwarf_seven, vector<int> v)
{
    if (end_flag)
        return;
    if (cnt == 7)
    {
        //print_vector(dwarf_seven);
        int sum = 0;
        for (int i = 0; i < 7; i++)
            sum += dwarf_seven[i];
        if (sum == 100)
        {
            for (int i = 0; i < 7; i++)
                cout << dwarf_seven[i] << "\n";
            end_flag = true;
            return;
        }
    }

    else
    {
        for (int i = 0; i < 9; i++)
            if (!visited[i])
            {
                visited[i] = 1;
                dwarf_seven.push_back(v[i]);
                backtracking(cnt + 1, dwarf_seven, v);
                visited[i] = 0;
                dwarf_seven.pop_back();
            }
    }
}

int main()
{
    vector<int> v;
    vector<int> d;

    for (int i = 0; i < 9; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    backtracking(0, d, v);
}
