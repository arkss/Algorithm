#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    long long fibo[90];
    
    fibo[0] = 0;
    fibo[1] = 1;
    
    for (int i=2;i<91;i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    
    int N;
    cin >> N;
    
    cout << fibo[N] << "\n";
    
    return 0;
}

