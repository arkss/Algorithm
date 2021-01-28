#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<char> str;
    list<char>::iterator cursor;

    string inputStr;
    cin >> inputStr;

    for (int i = 0; i < inputStr.size(); i++)
        str.push_back(inputStr[i]);

    int n;
    cin >> n;

    cursor = str.end();

    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;

        if (c == 'L')
        {
            if (cursor == str.begin())
                continue;
            cursor--;
        }
        else if (c == 'D')
        {
            if (cursor == str.end())
                continue;
            cursor++;
        }
        else if (c == 'B')
        {
            if (cursor == str.begin())
                continue;
            cursor--;
            cursor = str.erase(cursor);
        }
        else if (c == 'P')
        {
            char input;
            cin >> input;

            str.insert(cursor, input);
        }
    }

    for (char c : str)
        cout << c;
}
