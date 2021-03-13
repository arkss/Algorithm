#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id)
{
    string answer = "";

    // 1단계
    for (char &c : new_id)
        if ('A' <= c && c <= 'Z')
            c = c + ('a' - 'A');

    // 2단계
    string temp = "";
    for (char c : new_id)
    {
        if (('a' <= c && c <= 'z') || ('0' <= c && c <= '9') || c == '-' || c == '_' || c == '.')
            temp += c;
    }

    // 3단계
    char prev = 'a';
    for (char c : temp)
    {
        if (prev == '.' && c == '.')
            continue;
        answer += c;
        prev = c;
    }

    // 4단계
    if (answer[0] == '.')
        answer = answer.substr(1);
    if (answer[int(answer.size()) - 1] == '.')
        answer = answer.substr(0, int(answer.size()) - 1);

    // 5단계
    if (answer.empty())
        answer += 'a';

    // 6단계
    if (answer.size() >= 16)
        answer = answer.substr(0, 15);
    if (answer[0] == '.')
        answer = answer.substr(1);
    if (answer[int(answer.size()) - 1] == '.')
        answer = answer.substr(0, int(answer.size()) - 1);

    // 7단계
    while (answer.size() <= 2)
        answer += answer[int(answer.size()) - 1];
    return answer;
}

int main()
{
    cout << solution("...!@BaT#*..y.abcdefghijklm") << "\n";
    cout << solution("aaaaaaaaaaaaaaaaaaa") << "\n";
    cout << solution("aaaaaaaaaaaaaa.aaaa") << "\n";
    cout << solution("") << "\n";
    cout << solution("...abc..DEF...!@T..") << "\n";
    cout << solution(".........................") << "\n";
    cout << solution("..................................ab...") << "\n";
    cout << solution("~!@#$%&*()1=+[{]}.:?,<d>/") << "\n";
    cout << solution(".1.") << "\n";
    cout << solution("1234567890") << "\n";
    cout << solution("ABCDFERFADSDW") << "\n";
}