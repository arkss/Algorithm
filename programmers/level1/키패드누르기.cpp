#include <iostream>
#include <string>
#include <vector>

using namespace std;

int abs(int n)
{
    if (n < 0)
        return -n;
    else
        return n;
}

int calcurate_distance(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

string solution(vector<int> numbers, string hand)
{
    string answer = "";

    pair<int, int> leftPos = {3, 0};
    pair<int, int> rightPos = {3, 2};

    pair<int, int> numPos;

    for (int number : numbers)
    {
        if (number == 0)
            numPos = {3, 1};
        else
        {
            int x = (number - 1) / 3;
            int y = ((number - 1) % 3);
            numPos = {x, y};
        }
        if (number == 1 || number == 4 || number == 7)
        {
            answer += "L";
            leftPos = numPos;
        }
        else if (number == 3 || number == 6 || number == 9)
        {
            answer += "R";
            rightPos = numPos;
        }
        else
        {
            int leftDis = calcurate_distance(leftPos, numPos);
            int rightDis = calcurate_distance(rightPos, numPos);

            if (leftDis < rightDis)
            {
                answer += "L";
                leftPos = numPos;
            }
            else if (leftDis > rightDis)
            {
                answer += "R";
                rightPos = numPos;
            }
            else
            {
                if (hand == "right")
                {
                    answer += "R";
                    rightPos = numPos;
                }
                else
                {
                    answer += "L";
                    leftPos = numPos;
                }
            }
        }
    }

    return answer;
}

int main()
{
    solution({1, 2, 3, 4, 5, 6, 7, 8, 9}, "right");
}