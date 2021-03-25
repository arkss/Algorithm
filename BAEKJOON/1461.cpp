#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int totalStepCnt = 0;
    int N, M;
    cin >> N >> M;

    vector<int> positive = {0};
    vector<int> negative = {0};

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (num > 0)
            positive.push_back(num);
        else
            negative.push_back(-num);
    }

    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end());

    int posRest = positive.size() % M;
    int posIdx = (posRest + M - 1) % M;
    //cout << posIdx << "\n";
    while (1)
    {
        if (posIdx != positive.size() - 1)
        {
            totalStepCnt += positive[posIdx] * 2;
            posIdx += M;
        }
        else
        {
            totalStepCnt += positive[posIdx];
            break;
        }
    }

    //cout << totalStepCnt << "\n";

    int negRest = negative.size() % M;
    int negIdx = (negRest + M - 1) % M;
    while (1)
    {
        if (negIdx != negative.size() - 1)
        {
            totalStepCnt += negative[negIdx] * 2;
            negIdx += M;
        }
        else
        {
            totalStepCnt += negative[negIdx];
            break;
        }
    }

    totalStepCnt += min(positive[positive.size() - 1], negative[negative.size() - 1]);

    cout << totalStepCnt << "\n";
}