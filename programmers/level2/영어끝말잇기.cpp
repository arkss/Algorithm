#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<string, int> wordMap;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;
    char prevLastChar = words[0][0];
    bool hasDropout = false;

    for (int i = 0; i < words.size(); i++)
    {
        if (wordMap.find(words[i]) != wordMap.end())
        {
            hasDropout = true;
            answer.push_back((i % n) + 1);
            answer.push_back((i / n) + 1);
            //cout << words[i] << "\n";
            break;
        }

        if (prevLastChar != words[i][0])
        {
            hasDropout = true;
            answer.push_back((i % n) + 1);
            answer.push_back((i / n) + 1);
            break;
        }

        wordMap[words[i]] = 0;
        prevLastChar = words[i][words[i].length() - 1];
    }

    if (!hasDropout)
    {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}
int main()
{

    solution(3, {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"});
}