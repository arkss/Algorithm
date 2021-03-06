#include <iostream>
#include <stack>

using namespace std;

bool check_correct(string p)
{
    stack<char> s;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == '(')
            s.push(p[i]);
        else if (p[i] == ')')
        {
            if (s.empty())
                return false;
            if (s.top() == '(')
                s.pop();
            else if (s.top() == ')')
                return false;
        }
    }
    if (!s.empty())
        return false;
    else
        return true;
}

string solution(string p)
{
    // 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
    if (p.size() == 0)
        return "";

    // 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다.
    int left_cnt = 0, right_cnt = 0;
    string u, v;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == '(')
            left_cnt++;
        else if (p[i] == ')')
            right_cnt++;
        if (left_cnt == right_cnt)
        {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }

    if (left_cnt != right_cnt)
    {
        u = p;
        v = "";
    }

    // 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
    //   3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.
    if (check_correct(u))
        return u + solution(v);

    // 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
    //   4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
    //   4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
    //   4-3. ')'를 다시 붙입니다.
    //   4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
    //   4-5. 생성된 문자열을 반환합니다.
    else
    {
        string temp = "(" + solution(v) + ")";
        string change_u = u.substr(1, u.size() - 2);
        for (int i = 0; i < change_u.size(); i++)
        {
            if (change_u[i] == '(')
                temp += ")";
            else if (change_u[i] == ')')
                temp += "(";
        }
        return temp;
    }
}

int main()
{
    cout << solution(")(") << "\n";
}