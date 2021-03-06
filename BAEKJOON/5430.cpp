#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter)
{
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter))
    {
        answer.push_back(temp);
    }

    return answer;
}

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        string cmd;
        cin >> cmd;

        int arr[100001];
        int arrLength;
        cin >> arrLength;

        string arrStr;
        cin >> arrStr;
        arrStr = arrStr.substr(1);
        arrStr.pop_back();

        vector<string> v = split(arrStr, ',');

        int sIdx = 0;
        int eIdx = int(v.size()) - 1;
        bool isReverse = false;

        for (int i = 0; i < cmd.size(); i++)
        {
            if (cmd[i] == 'R')
                isReverse = !isReverse;

            else
            {
                if (isReverse)
                    eIdx--;
                else
                    sIdx++;
            }
        }

        if ((sIdx - eIdx != 1) && eIdx < sIdx)
            cout << "error\n";
        else
        {
            if (isReverse)
            {
                cout << "[";
                for (int i = eIdx; i >= sIdx; i--)
                {
                    cout << v[i];
                    if (i != sIdx)
                        cout << ",";
                }
                cout << "]\n";
            }
            else
            {
                cout << "[";
                for (int i = sIdx; i <= eIdx; i++)
                {
                    cout << v[i];
                    if (i != eIdx)
                        cout << ",";
                }
                cout << "]\n";
            }
        }
    }
}