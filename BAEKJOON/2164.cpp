#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    bool is_discard_turn = true;
    while (q.size() != 1)
    {
        if (!is_discard_turn)
            q.push(q.front());
        q.pop();
        is_discard_turn = !is_discard_turn;
    }
    cout << q.front() << "\n";
    return 0;
}