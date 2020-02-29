#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int> > commands)
{
    vector<int> answer;

    for (int i=0;i<commands.size();i++){
        int startIndex = commands[i][0]-1;
        int endIndex = commands[i][1]-1;
        int index = commands[i][2]-1;

        vector<int> temp;
        temp.assign(array.begin()+startIndex, array.begin()+endIndex+1);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[index]);
    }
    return answer;
}

int main()
{
    vector<int> array;
    vector<vector<int> > commands;
    
    array.push_back(1);
    array.push_back(5);
    array.push_back(2);
    array.push_back(6);
    array.push_back(3);
    array.push_back(7);
    array.push_back(4);

    vector<int> temp1;
    vector<int> temp2;
    vector<int> temp3;
    temp1.push_back(2);
    temp1.push_back(5);
    temp1.push_back(3);
    temp2.push_back(4);
    temp2.push_back(4);
    temp2.push_back(1);
    temp3.push_back(1);
    temp3.push_back(7);
    temp3.push_back(3);
    commands.push_back(temp1);
    commands.push_back(temp2);
    commands.push_back(temp3);
    solution(array, commands);
    return 0;
}