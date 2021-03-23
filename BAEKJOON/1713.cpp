#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// visited<i,j,k> : k번째 학생이 i의 추천 수를 받고 j index에 액자에 걸렸다.
vector<pair<pair<int, int>, int>> frames;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if (a.first.first == b.first.first)
        return a.first.second < b.first.second;

    return a.first.first < b.first.first;
}

bool cmpBystudentNum(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.second < b.second;
}

int main()
{
    int frameSize;
    cin >> frameSize;

    frames.resize(frameSize);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int studentNum;
        cin >> studentNum;

        bool isInFrame = false;
        for (int i = 0; i < frames.size(); i++)
        {
            if (frames[i].second == studentNum)
            {
                isInFrame = true;
                frames[i].first.first++;
            }
        }

        // 액자에 없으면
        if (!isInFrame)
        {
            // 액자가 비었으면
            if (frames.size() != frameSize)
                frames.push_back({{1, i}, studentNum});

            // 액자가 차있으면
            else
            {
                sort(frames.begin(), frames.end(), cmp);
                frames[0] = {{1, i}, studentNum};
            }
        }
    }

    sort(frames.begin(), frames.end(), cmpBystudentNum);
    for (int i = 0; i < frameSize; i++)
        cout << frames[i].second << " ";
}