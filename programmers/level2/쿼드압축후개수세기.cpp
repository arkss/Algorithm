#include <string>
#include <vector>

using namespace std;

vector<int> answer;
vector<vector<int>> board;

void compression(int x, int y, int size)
{
    if (size == 1)
    {
        answer[board[x][y]]++;
        return;
    }

    int value = board[x][y];
    bool isAllSame = true;
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (value != board[i][j])
            {
                isAllSame = false;
                i = x + size;
                j = y + size;
            }
        }
    }

    if (isAllSame)
        answer[value]++;
    else
    {
        int halfSize = size / 2;
        compression(x, y, halfSize);
        compression(x + halfSize, y, halfSize);
        compression(x, y + halfSize, halfSize);
        compression(x + halfSize, y + halfSize, halfSize);
    }
}

vector<int> solution(vector<vector<int>> arr)
{
    answer.resize(2);
    board = arr;
    compression(0, 0, arr.size());

    return answer;
}

int main()
{

}