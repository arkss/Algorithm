#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int rowPlusCol = brown / 2 + 2;
    for (int col=1;col<rowPlusCol;col++){
        int row = rowPlusCol - col;
        if ((row-2)*(col-2) == red){
            answer.push_back(row);
            answer.push_back(col);
            break;
        }
    }
    return answer;
}

int main(){

}