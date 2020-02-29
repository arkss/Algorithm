#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr){
    vector<int> answer;
    for (int item : arr){
        if (answer.size() != 0 && answer[answer.size()-1] == item){
            continue;
        }
        else {
            answer.push_back(item);
        }
    }
    return answer;
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(1);


}