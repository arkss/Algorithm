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
    cout << sumValue << " " << originX << "\n"; 
    if (sumValue % originX == 0) return true;
    else return false;
}

int main(){
    cout << solution(10) << "\n";
    return 0;
}