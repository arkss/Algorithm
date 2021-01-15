#include <iostream>

using namespace std;
// B T R L RT LT RB LB
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

struct Item
{
    int x;
    int y;
};

int abs(int a)
{
    return a > 0 ? a : (-1) * a;
}

int main()
{
    Item items[2];

    for (int i = 0; i < 2; i++)
    {
        string pos;
        cin >> pos;

        items[i].y = (pos[0] - 'A');
        items[i].x = abs((pos[1] - '0') - 8);
    }

    int move_num;
    cin >> move_num;

    for (int i = 0; i < move_num; i++)
    {
        string command;
        cin >> command;

        int intDir;

        if (command == "B")
            intDir = 0;
        else if (command == "T")
            intDir = 1;
        else if (command == "R")
            intDir = 2;
        else if (command == "L")
            intDir = 3;
        else if (command == "RT")
            intDir = 4;
        else if (command == "LT")
            intDir = 5;
        else if (command == "RB")
            intDir = 6;
        else if (command == "LB")
            intDir = 7;

        int king_nx = items[0].x + dx[intDir];
        int king_ny = items[0].y + dy[intDir];

        if (0 > king_nx || king_nx > 7 || 0 > king_ny || king_ny > 7)
            continue;

        if (king_nx == items[1].x && king_ny == items[1].y)
        {
            int stone_nx = items[1].x + dx[intDir];
            int stone_ny = items[1].y + dy[intDir];

            if (0 > stone_nx || stone_nx > 7 || 0 > stone_ny || stone_ny > 7)
                continue;

            items[1].x = stone_nx;
            items[1].y = stone_ny;
        }

        items[0].x = king_nx;
        items[0].y = king_ny;
    }

    for (int i = 0; i < 2; i++)
    {
        cout << char(items[i].y + 'A') << abs(items[i].x - 8) << "\n";
    }
}

//   a b c d e f g h
// 8
// 7
// 6
// 5
// 4
// 3
// 2
// 1

//   0 1 2 3 4 5 6 7
// 0
// 1
// 2
// 3
// 4
// 5
// 6
// 7
