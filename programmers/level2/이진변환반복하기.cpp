#include <iostream>
#include <string>
#include <vector>

using namespace std;

int changeCnt;
int deleteZeroCnt;

string delete_zero(string s)
{
    string strWithoutZero = "";
    for (char c : s)
    {
        if (c == '0')
            deleteZeroCnt++;
        else
        {
            strWithoutZero += '1';
        }
    }

    return strWithoutZero;
}

string change_binary(int n)
{
    string s = "";
    while (n != 0)
    {
        s += to_string(n % 2);
        n /= 2;
    }

    return s;
}

vector<int> solution(string s)
{
    vector<int> answer;

    while (1)
    {
        cout << s << "\n";

        s = delete_zero(s);
        s = change_binary(s.length());
        changeCnt++;

        if (s == "1")
            break;
    }

    answer.push_back(changeCnt);
    answer.push_back(deleteZeroCnt);

    cout << changeCnt << " " << deleteZeroCnt << "\n";
    return answer;
}

int main()
{
    vector<int> rst = solution("110010101001");
}