#include <iostream>

using namespace std;

int solution(int n){
    int fibo[100001] = {0,1};
    for (int i=2;i<100001;i++){
        fibo[i] = (fibo[i-1] + fibo[i-2]) % 1234567;
    }

    return fibo[n];
}

int main(){
    cout << solution(100000) << "\n";
}