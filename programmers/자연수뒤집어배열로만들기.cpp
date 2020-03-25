#include <iostream>

using namespace std;

vector<int> solution(long long n){
    vector<int> answer;
    while (1){
        int temp = n % 10;
        n = n / 10;
        answer.push_back(temp);
        if (n == 0) break;
    }
    
    return answer;
}

int main(){

}