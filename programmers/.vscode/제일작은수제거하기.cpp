#include <iostream>

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
}

int main(){

}