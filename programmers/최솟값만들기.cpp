#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), compare);

    for (int i = 0; i < A.size(); i++)
    {
        answer += A[i] * B[i];
    }
    return answer;
}

int main()
{
    vector<int> a;
    vector<int> b;
    a.push_back(1);
    a.push_back(4);
    a.push_back(2);
    b.push_back(5);
    b.push_back(4);
    b.push_back(4);
    cout << solution(a, b) << "\n";
}