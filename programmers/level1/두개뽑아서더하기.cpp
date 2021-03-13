#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int addRsts[201];

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;
    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            addRsts[numbers[i] + numbers[j]] = 1;
        }
    }

    for (int i = 0; i < 201; i++)
    {
        if (addRsts[i])
            answer.push_back(i);
    }
    return answer;
}

