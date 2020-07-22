#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scovile, int x)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scovile.begin(), scovile.end());
    while (1)
    {
        if (pq.top() >= x)
            break;
        if (pq.size() == 1)
            return -1;
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + second * 2);
        answer++;
    }
    return answer;
}

int main()
{
    vector<int> v = {1, 2, 3, 9, 10, 12};
    int K = 7;
    cout << solution(v, K) << "\n";
}