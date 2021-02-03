#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int results[500001];

int main()
{
    int N;
    cin >> N;

    vector<int> topHs;
    // height, index
    stack<pair<int, int>> st;

    for (int i = 0; i < N; i++)
    {
        int topH;
        cin >> topH;

        topHs.push_back(topH);
    }

    for (int i = 0; i < N; i++)
    {
        if (st.empty())
        {
            st.push({topHs[i], i + 1});
        }
        else if (st.top().first < topHs[i])
        {
            while (st.top().first < topHs[i])
            {
                st.pop();
                if (st.empty())
                    break;
            }
            if (!st.empty())
                results[i] = st.top().second;
            st.push({topHs[i], i + 1});
        }
        else
        {
            results[i] = st.top().second;
            st.push({topHs[i], i + 1});
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << results[i] << " ";
    }
    cout << "\n";
}
