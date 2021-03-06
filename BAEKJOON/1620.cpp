#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> m1;
vector<string> v1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    v1.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        string name;
        cin >> name;

        m1[name] = i;
        v1[i] = name;
    }

    for (int i = 0; i < M; i++)
    {
        string question;
        cin >> question;

        if ('0' <= question[0] && question[0] <= '9')
        {
            cout << v1[stoi(question)] << "\n";
        }

        else
            cout << m1[question] << "\n";
    }
}