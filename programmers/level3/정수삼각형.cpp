#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle){
    int answer = 0;

    for (int i=1;i<triangle.size();i++){
        vector<int> row = triangle[i];
        for(int j=0;j<row.size();j++){
            if (j == 0) row[j] += triangle[i-1][j];
            else if (j == row.size()-1) row[j] += triangle[i-1][j-1];
            else row[j] += max(triangle[i-1][j-1], triangle[i-1][j]);
            triangle[i][j] = row[j];
        }
    }

    for (int i=0;i<triangle.size();i++){
        answer = max(answer, triangle[triangle.size()-1][i]);
    }

    return answer;
}

int main(){
    cout << solution({{7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5}}) << "\n";
    return 0;
}