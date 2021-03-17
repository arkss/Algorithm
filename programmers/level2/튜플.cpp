#include <iostream>
#include <string>
#include <vector>

using namespace std;

// arr[i] : 원소의 개수가 i인 튜플의 원소들
vector<int> arr[1001];
int visited[100001];

vector<int> solution(string s)
{
    vector<int> answer;

    int tupleLen = 1;
    int setLen = 0;
    int tempNum = 0;
    vector<int> tempTuple;

    for (int i = 1; i < s.length() - 1; i++)
    {
        char c = s[i];
        if (c == '{')
            continue;
        else if (c == '}' || c == ',')
        {
            tempTuple.push_back(tempNum);
            tempNum = 0;

            if (c == ',')
                tupleLen++;

            else
            {
                for (int j = 0; j < tempTuple.size(); j++)
                    arr[tupleLen].push_back(tempTuple[j]);

                tupleLen = 1;
                setLen++;
                tempTuple.clear();
                // 집합과 집합 사이의 , 무시
                i++;
            }
        }
        else if (c == ',')
        {
            tempTuple.push_back(tempNum);
            tupleLen++;
            tempNum = 0;
        }
        else
            tempNum = tempNum * 10 + (c - '0');
    }

    for (int i = 1; i <= setLen; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (!visited[arr[i][j]])
            {
                answer.push_back(arr[i][j]);
                visited[arr[i][j]] = 1;
            }
        }
    }
    return answer;
}

int main()
{

    vector<int> rst = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
    cout << "main\n";
    for (int num : rst)
    {
        cout << num << " ";
    }
}