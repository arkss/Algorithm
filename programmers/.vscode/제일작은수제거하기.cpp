#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr){
    int minValue = 987654321;
    int minIndex = -1;
    for (int i=0;i<arr.size();i++){
        if (arr[i] < minValue){
            minValue = arr[i];
            minIndex = i;
        }
    }
    arr.erase(arr.begin()+minIndex);
    if (arr.empty()) arr.push_back(-1);
    return arr;
}

int main(){
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);
    solution(arr);
}