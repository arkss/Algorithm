#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < participant.size(); i++)
    {
        if (participant[i] != completion[i])
        {
            return participant[i];
        }
    }
}

int main()
{
    vector<string> participant;
    vector<string> completion;

    participant.push_back("leo");
    participant.push_back("kiki");
    participant.push_back("eden");

    completion.push_back("eden");
    completion.push_back("kiki");

    cout << solution(participant, completion) << "\n";

    return 0;
}
