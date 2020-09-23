#include <iostream>
#include <vector>

using namespace std;

// 한 번 돈 애가 다시 돌지 않는구나... 후

// N극은 0, S극은 1
string s[4];

void print_s()
{
    cout << "\n";
    for (int i = 0; i < 4; i++)
    {
        cout << s[i] << "\n";
    }
    cout << "\n";
}

void move(int idx, int dir)
{
    //cout << idx << " " << dir << "\n";
    if (idx < 0 || idx > 3)
        return;

    // ->
    if (dir == 1)
    {
        char temp = s[idx][7];
        for (int i = 6; i >= 0; i--)
            s[idx][i + 1] = s[idx][i];

        s[idx][0] = temp;
    }
    // <-
    else
    {
        char temp = s[idx][0];
        for (int i = 1; i <= 7; i++)
            s[idx][i - 1] = s[idx][i];

        s[idx][7] = temp;
    }
}

void go_left(int idx, int dir)
{
    if (idx < 0 || idx > 3)
        return;

    if (s[idx][2] != s[idx + 1][6])
    {
        go_left(idx - 1, dir * -1);
        move(idx, dir);
    }
}

void go_right(int idx, int dir)
{
    if (idx < 0 || idx > 3)
        return;

    if (s[idx][6] != s[idx - 1][2])
    {
        go_right(idx + 1, dir * -1);
        move(idx, dir);
    }
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        cin >> s[i];
    }

    int cmd_num;
    cin >> cmd_num;

    for (int i = 0; i < cmd_num; i++)
    {
        // dir 1: ->, -1: <-
        int idx, dir;
        cin >> idx >> dir;
        idx = idx - 1;

        go_left(idx - 1, dir * -1);
        go_right(idx + 1, dir * -1);
        move(idx, dir);

        //print_s();
    }

    int answer = 0;

    vector<int> points = {1, 2, 4, 8};

    for (int i = 0; i < 4; i++)
        if (s[i][0] == '1')
            answer += points[i];

    cout << answer << "\n";
}