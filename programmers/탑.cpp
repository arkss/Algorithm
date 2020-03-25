#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> heights){
    vector<int> answer;
    reverse(heights.begin(), heights.end());
    for (int i=0;i<heights.size();i++){
        //cout << heights[i] << "\n";
        int j;
        for (j=i+1;j<heights.size();j++){
            if (heights[j] > heights[i]){
                answer.push_back(heights.size()-j);
                break;
            }
        }
        if (j==heights.size()) {
            answer.push_back(0);
        }
    }

    reverse(answer.begin(), answer.end());
    return answer;
}

int main(){
    vector<int> heights;
    heights.push_back(6);
    heights.push_back(9);
    heights.push_back(5);
    heights.push_back(7);
    heights.push_back(4);
    solution(heights);
}