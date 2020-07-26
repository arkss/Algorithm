// #include <iostream>
// #include <vector>

// using namespace std;

// vector<int> solution(int brown, int red) {
//     vector<int> answer;
//     int rowPlusCol = brown / 2 + 2;
//     for (int col=1;col<rowPlusCol;col++){
//         int row = rowPlusCol - col;
//         if ((row-2)*(col-2) == red){
//             answer.push_back(row);
//             answer.push_back(col);
//             break;
//         }
//     }
//     return answer;
// }

// int main(){

// }

#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    for (int brown_row = 3; brown_row <= (brown - 2) / 2; brown_row++)
    {
        int brown_col = (brown + 4) / 2 - brown_row;
        int prediction = (brown_row - 2) * (brown_col - 2);
        if (prediction == yellow)
        {
            answer.push_back(brown_col);
            answer.push_back(brown_row);
            break;
        }
    }
    return answer;
}

int main()
{
    int brown = 10;
    int yellow = 2;
    solution(brown, yellow);
}