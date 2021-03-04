#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> m;

long long Find(long long n)
{
    if (m[n] == 0)
        return n;
    else
    {
        m[n] = Find(m[n]);
        return m[n];
    }
}

vector<long long> solution(long long k, vector<long long> room_number)
{
    vector<long long> answer;

    for (int i = 0; i < room_number.size(); i++)
    {
        long long num = room_number[i];

        // 방이 비어있을 경우
        if (m[num] == 0)
        {
            answer.push_back(num);
            m[num] = Find(num + 1);
        }
        else
        {
            long long next = Find(num);
            answer.push_back(next);
            m[next] = Find(next + 1);
        }
    }

    return answer;
}

int main()
{
    long long k = 1;
    vector<long long> room_number = {1, 3, 4, 2, 5, 6};
    vector<long long> answer = solution(10, room_number);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << "\n";
}