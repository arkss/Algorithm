#include <iostream>

using namespace std;

vector<int> solution(long long n){
    vector<int> answer;
    while (1){
        int temp = n % 10;
        n = n / 10;
        answer.push_back(temp);
    }
    
    return answer;
}

int main(){
    for (int i : solution(12345)){
        cout << i << "\n";
    }
}