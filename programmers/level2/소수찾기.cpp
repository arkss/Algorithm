#include <iostream>

using namespace std;

int numbers[1000000];

int solution(int n){
    int cnt = 0;

    for (int i=2;i<=n;i++){
        if (numbers[i] == 1) continue;
        for (int j=i*2;j<=n;j+=i){
            numbers[j] = 1;
        }
    }

    for (int i=2;i<=n;i++){
        if (numbers[i] == 0) cnt++;
    }

    return cnt;
}

int main(){
    cout << solution(1000) << "\n";
    return 0;
}