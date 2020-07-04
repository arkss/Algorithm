#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int visited[16];
vector<char> answer;

bool is_two_consonants_one_vowel(vector<char> v)
{
    int consonant = 0, vowel = 0;
    for (int i = 0; i < v.size(); i++)
    {
        char c = v[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vowel++;
        else
            consonant++;
    }
    if (consonant >= 2 && vowel >= 1)
        return true;
    else
        return false;
}

void backtracking(int L, vector<char> alphabets, int cnt)
{
    if (L == cnt && is_two_consonants_one_vowel(answer))
    {
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i];
        }
        cout << "\n";
    }

    else
    {
        for (int i = 0; i < alphabets.size(); i++)
        {
            if (answer.size() && answer[answer.size() - 1] > alphabets[i])
                continue;
            if (!visited[i])
            {
                visited[i] = 1;
                answer.push_back(alphabets[i]);
                backtracking(L, alphabets, cnt + 1);
                answer.pop_back();
                visited[i] = 0;
            }
        }
    }
}

int main()
{
    int L, C;
    cin >> L >> C;

    vector<char> alphabets;
    for (int i = 0; i < C; i++)
    {
        char alphabet;
        cin >> alphabet;
        alphabets.push_back(alphabet);
    }

    sort(alphabets.begin(), alphabets.end());

    backtracking(L, alphabets, 0);
}