#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<char> answer;
    string s, bomb;
    cin >> s >> bomb;

    answer.resize(s.size());

    int idx = 0;
    int bomb_size = bomb.size();

    for (int i = 0; i < s.size(); i++)
    {
        bool is_bomb = true;
        answer[idx] = s[i];
        if (answer[idx] == bomb[bomb_size - 1])
        {
            for (int j = 0; j < bomb_size; j++)
            {
                if (idx - j < 0 || answer[idx - j] != bomb[bomb_size - 1 - j])
                {
                    is_bomb = false;
                    break;
                }
            }

            if (is_bomb)
                idx = max(0, idx - bomb_size + 1);
            else
                idx++;
        }
        else
            idx++;
    }

    if (idx)
        for (int i = 0; i < idx; i++)
            cout << answer[i];

    else
        cout << "FRULA\n";
}