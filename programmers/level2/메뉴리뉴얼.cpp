#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> menuMap;
int visited[21];

void init_visited()
{
    for (int i = 0; i < 21; i++)
        visited[i] = 0;
}

void backtracking(string order, int courseNum, int cnt, int idx, string menu)
{
    if (cnt == courseNum)
    {

        if (menuMap.find(menu) == menuMap.end())
            menuMap[menu] = 1;
        else
            menuMap[menu]++;

        //cout << menu << "\n";
        return;
    }
    for (int i = idx; i < order.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            menu += order[i];
            backtracking(order, courseNum, cnt + 1, i + 1, menu);
            menu = menu.substr(0, menu.length() - 1);
            visited[i] = 0;
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    for (string order : orders)
    {
        sort(order.begin(), order.end());
        //cout << order << "에 대한 목록\n";
        for (int courseNum : course)
        {
            init_visited();
            backtracking(order, courseNum, 0, 0, "");
        }
    }

    vector<string> answer;
    // maxCount[i] : i길이의 메뉴
    int maxCount[11] = {0};
    vector<string> tempAns[11];

    for (map<string, int>::iterator i = menuMap.begin(); i != menuMap.end(); i++)
    {
        string menuName = i->first;
        int menuLength = menuName.length();
        int menuCnt = i->second;

        //cout << menuName << " " << menuCnt << "\n";
        // 1개 나온 메뉴는 생략
        if (menuCnt >= 2)
        {
            if (maxCount[menuLength] < menuCnt)
            {
                tempAns[menuLength].clear();
                tempAns[menuLength].push_back(menuName);
                maxCount[menuLength] = menuCnt;
            }
            else if (maxCount[menuLength] == menuCnt)
            {
                tempAns[menuLength].push_back(menuName);
            }
        }
    }

    for (int i = 2; i < 11; i++)
    {
        for (string s : tempAns[i])
        {
            answer.push_back(s);
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    //solution({"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}, {2, 3, 4});
    vector<string> v = solution({"XYZ", "XWY", "WXA"}, {2, 3, 4});
    cout << "\n\n결과\n";
    for (string s : v)
    {
        cout << s << "\n";
    }
}