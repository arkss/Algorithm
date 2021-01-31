#include <iostream>
#include <stack>

using namespace std;

stack<int> st[7];

int main()
{

    int minMoveCnt = 0;
    // 음의 수, 프렛의 수
    int N, P;
    cin >> N >> P;

    for (int i = 0; i < N; i++)
    {
        int row, fret;
        cin >> row >> fret;

        if (st[row].empty())
        {
            st[row].push(fret);
            minMoveCnt++;
        }
        else
        {
            if (st[row].top() > fret)
            {
                while (st[row].top() > fret)
                {

                    st[row].pop();
                    minMoveCnt++;

                    if (st[row].empty())
                        break;
                }

                // 같은 줄, 같은 플렛이면 추가할 필요 X
                if (st[row].empty() || st[row].top() != fret)
                {
                    st[row].push(fret);
                    minMoveCnt++;
                }
            }

            else if (st[row].top() < fret)
            {
                st[row].push(fret);
                minMoveCnt++;
            }
        }
    }

    cout << minMoveCnt << "\n";
    return 0;
}