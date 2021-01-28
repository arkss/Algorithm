#include <iostream>
#include <vector>

using namespace std;

vector<string> words;
int N, K;
int visited[26];
int answer;

void backtracking(int idx, int cnt)
{
    if (K - 5 == cnt)
    {
        int possibleWordsNum = 0;

        for (int i = 0; i < words.size(); i++)
        {
            bool isPossible = true;
            for (int j = 0; j < words[i].size(); j++)
            {
                if (!visited[words[i][j] - 'a'])
                {
                    isPossible = false;
                    break;
                }
            }

            if (isPossible)
                possibleWordsNum++;
        }
        answer = max(answer, possibleWordsNum);
    }
    else
    {
        for (int i = idx; i < 26; i++)
        {
            if (!visited[i])
            {
                visited[i] = 1;
                backtracking(i, cnt + 1);
                visited[i] = 0;
            }
        }
    }
}

int main()
{

    cin >> N >> K;

    if (K < 5)
    {
        cout << "0\n";
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        s = s.substr(4, s.size() - 8);
        words.push_back(s);
    }

    visited['a' - 'a'] = 1;
    visited['n' - 'a'] = 1;
    visited['t' - 'a'] = 1;
    visited['i' - 'a'] = 1;
    visited['c' - 'a'] = 1;

    backtracking(0, 0);
    cout << answer << "\n";
}