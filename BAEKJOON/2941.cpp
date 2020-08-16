#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int cnt = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (i + 1 <= s.size() - 1)
        {
            if (s[i] == 'c' && s[i + 1] == '=')
                i++;
            else if (s[i] == 'c' && s[i + 1] == '-')
                i++;
            else if (s[i] == 'd' && s[i + 1] == '-')
                i++;
            else if (s[i] == 'l' && s[i + 1] == 'j')
                i++;
            else if (s[i] == 'n' && s[i + 1] == 'j')
                i++;
            else if (s[i] == 's' && s[i + 1] == '=')
                i++;
            else if (s[i] == 'z' && s[i + 1] == '=')
                i++;
            if (i + 2 <= s.size() - 1)
                if (s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '=')
                    i += 2;
        }

        cnt++;
        cout << s[i] << " ";
    }

    cout << cnt << "\n";
}