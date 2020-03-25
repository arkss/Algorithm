#include <iostream>
#include <vector>

using namespace std;

bool solution(int x){
    int sumValue = 0;
    int originX = x;
    while (1){
        sumValue += x%10;
        x = x/10;
        if (x == 0) break;
    }
    if (originX % sumValue == 0) return true;
    else return false;
}

int main(){
    cout << solution(10) << "\n";
    return 0;
}