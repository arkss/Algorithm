#include <iostream>

using namespace std;

int dp[5002];

// 2자리수가 알파벳이 될 수 있는지 확인
bool checkAlphabet(char t, char o)
{
    if (t == '1')
        return true;
    else if (t == '2')
        if ('0' <= o && o <= '6')
            return true;
    return false;
}

bool checkCorrect(char t, char o)
{
    if (o == '0')
        if (t == '0' || '3' <= t)
            return false;
    return true;
}

int main()
{
    string s;
    cin >> s;

    if (s[0] == '0')
    {
        cout << 0;
        return 0;
    }

    dp[0] = dp[1] = 1;
    bool isCorrect = true;

    for (int i = 2; i <= s.size(); i++)
    {
        if (!checkCorrect(s[i - 2], s[i - 1]))
        {
            isCorrect = false;
            break;
        }

        if (s[i - 1] == '0')
            dp[i] = dp[i - 2];

        else if (checkAlphabet(s[i - 2], s[i - 1]))
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
        else
            dp[i] = dp[i - 1];
    }

    if (isCorrect)
        cout << dp[s.size()] << "\n";
    else
        cout << 0 << "\n";
}