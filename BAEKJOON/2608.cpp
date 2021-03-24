#include <iostream>
#include <map>

using namespace std;

map<string, int> m;

void init_map()
{
    m["I"] = 1;
    m["V"] = 5;
    m["X"] = 10;
    m["L"] = 50;
    m["C"] = 100;
    m["D"] = 500;
    m["M"] = 1000;

    m["IV"] = 4;
    m["IX"] = 9;
    m["XL"] = 40;
    m["XC"] = 90;
    m["CD"] = 400;
    m["CM"] = 900;
}

int roma_to_int(string s)
{
    int rst = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (i < s.size() - 1)
        {
            string twoChar = s.substr(i, 2);
            if (m.find(twoChar) != m.end())
            {
                rst += m[twoChar];

                i++;
                continue;
            }
        }
        string temp;
        temp += s[i];
        rst += m[temp];
    }

    return rst;
}

string int_to_roma(int num)
{
    string rst = "";

    for (int i = 0; i < 3; i++)
        if (num >= 1000)
        {
            num -= 1000;
            rst += "M";
        }

    if (num >= 900)
    {
        num -= 900;
        rst += "CM";
    }

    if (num >= 500)
    {
        num -= 500;
        rst += "D";
    }

    if (num >= 400)
    {
        num -= 400;
        rst += "CD";
    }

    for (int i = 0; i < 3; i++)
        if (num >= 100)
        {
            num -= 100;
            rst += "C";
        }

    if (num >= 90)
    {
        num -= 90;
        rst += "XC";
    }

    if (num >= 50)
    {
        num -= 50;
        rst += "L";
    }

    if (num >= 40)
    {
        num -= 40;
        rst += "XL";
    }

    for (int i = 0; i < 3; i++)
        if (num >= 10)
        {
            num -= 10;
            rst += "X";
        }

    if (num >= 9)
    {
        num -= 9;
        rst += "IX";
    }

    if (num >= 5)
    {
        num -= 5;
        rst += "V";
    }

    if (num >= 4)
    {
        num -= 4;
        rst += "IV";
    }

    for (int i = 0; i < 3; i++)
        if (num >= 1)
        {
            num -= 1;
            rst += "I";
        }

    return rst;
}

int main()
{
    init_map();

    string s1;
    string s2;

    cin >> s1 >> s2;
    /*
    cout << roma_to_int(s1) << "\n";
    cout << roma_to_int(s2) << "\n";
    */
    int intSum = roma_to_int(s1) + roma_to_int(s2);
    string romaSum = int_to_roma(intSum);

    cout << intSum << "\n";
    cout << romaSum << "\n";

    //cout << int_to_roma(235) << " " << int_to_roma(2493) << "\n";
}