#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string input;
    stack<char> s;

    int result = 0;
    int temp = 1;

    bool isValid = true;

    cin >> input;

    for (int i = 0; i < input.size(); i++)
    {
        char c = input[i];

        if (c == '(')
        {
            s.push('(');
            temp *= 2;
        }
        else if (c == '[')
        {
            s.push('[');
            temp *= 3;
        }

        else if (c == ')')
        {
            if (s.empty() || (!s.empty() && s.top() != '('))
            {
                isValid = false;
                break;
            }

            if (input[i - 1] == '(')
                result += temp;

            s.pop();
            temp /= 2;
        }

        else if (c == ']')
        {
            if (s.empty() || (!s.empty() && s.top() != '['))
            {
                isValid = false;
                break;
            }

            if (input[i - 1] == '[')
                result += temp;

            s.pop();
            temp /= 3;
        }
    }

    if (!isValid || !s.empty())
        cout << 0 << "\n";
    else
        cout << result << "\n";
}
