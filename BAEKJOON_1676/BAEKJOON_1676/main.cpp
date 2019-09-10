#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    int zeroCount = 0;
    
    for (int i=1;i<=N;i++){
        int num = i;
        while (num%5==0){
            zeroCount++;
            num /= 5;
        }
    }
    cout << zeroCount << "\n";
    return 0;
}
