#include <iostream>
#include <vector>
#include <memory.h>
#include <string>

using namespace std;

// possible_num_board[i][j] : 들어온 i 번째 수로 j 값을 만들 수 있는가
bool possible_num_board[10][10];
vector<int> possible_nums;

vector<string> nums = {
    "####.##.##.####",
    "..#..#..#..#..#",
    "###..#####..###",
    "###..####..####",
    "#.##.####..#..#",
    "####..###..####",
    "####..####.####",
    "###..#..#..#..#",
    "####.#####.####",
    "####.####..####"};

void print_possible_num_board(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << possible_num_board[i][j] << " ";
        }
        cout << "\n";
    }
}

void backtracking(int N, int idx, int num)
{
    if (idx == N)
    {
        possible_nums.push_back(num);
    }

    else
    {
        for (int i = 0; i < 10; i++)
        {
            if (possible_num_board[idx][i])
            {
                backtracking(N, idx + 1, num * 10 + i);
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;

    memset(possible_num_board, true, sizeof(possible_num_board));

    vector<string> input_nums;
    input_nums.resize(N);

    for (int i = 0; i < 5; i++)
    {
        string row;
        cin >> row;

        int sidx = 0;

        for (int j = 0; j < N; j++)
        {
            input_nums[j] += row.substr(sidx, 3);
            sidx += 4;
        }
    }
    for (int i = 0; i < N; i++)
    {
        string input_num = input_nums[i];
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 15; k++)
            {
                if (input_num[k] == '#' && nums[j][k] == '.')
                {
                    possible_num_board[i][j] = false;
                }
            }
        }
    }
    //print_possible_num_board(N);

    backtracking(N, 0, 0);

    double possible_sum = 0;

    for (int i = 0; i < possible_nums.size(); i++)
    {
        possible_sum += possible_nums[i];
    }
    if (possible_sum == 0)
        cout << -1 << "\n";
    else
        cout << possible_sum / possible_nums.size() << "\n";
}