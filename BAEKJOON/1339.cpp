#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[10];
int answer;

void print_v(vector<char> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

bool find(vector<char> alphabets, char c)
{
    for (int i = 0; i < alphabets.size(); i++)
    {
        if (alphabets[i] == c)
            return true;
    }
    return false;
}

int cal(int N, vector<char> alphabets,
        int alphabets_value[10],
        string s[10])
{
    int total_sum = 0;
    for (int i = 0; i < N; i++)
    {
        int partial_sum = 0;
        string temp = s[i];
        for (int j = 0; j < temp.size(); j++)
        {
            for (int k = 0; k < alphabets.size(); k++)
            {
                if (temp[j] == alphabets[k])
                {
                    partial_sum = partial_sum * 10 + alphabets_value[k];
                    break;
                }
            }
        }
        total_sum += partial_sum;
    }
    return total_sum;
}

void backtracking(int N, vector<char> alphabets,
                  int alphabets_value[10],
                  string s[10], int cnt)
{
    if (alphabets.size() == cnt)
    {
        int sum_value = cal(N, alphabets, alphabets_value, s);
        answer = max(answer, sum_value);
    }
    else
    {
        for (int i = 9; i > 9 - (int)alphabets.size(); i--)
        {
            if (!visited[i])
            {
                alphabets_value[cnt] = i;
                visited[i] = true;
                backtracking(N, alphabets, alphabets_value, s, cnt + 1);
                visited[i] = false;
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;

    string s[10];
    vector<char> alphabets;
    int alphabets_value[10];

    for (int i = 0; i < N; i++)
    {
        cin >> s[i];
        for (int j = 0; j < s[i].size(); j++)
        {
            if (!find(alphabets, s[i][j]))
                alphabets.push_back(s[i][j]);
        }
    }
    //print_v(alphabets);
    backtracking(N, alphabets, alphabets_value, s, 0);
    cout << answer << "\n";
}