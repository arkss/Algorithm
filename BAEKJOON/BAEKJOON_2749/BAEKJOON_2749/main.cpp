#include <iostream>

using namespace std;

long long fibo[1500000];

int main(int argc, const char * argv[]) {
    
    fibo[0] = 0;
    fibo[1] = 1;
    
    for (int i=2;i<1500000;i++){
        fibo[i] = (fibo[i-1] + fibo[i-2]) % 1000000;
    }
    
    long long N;
    cin >> N;
    N = N % 1500000;
    
    cout << fibo[N] << "\n";
    
    return 0;
}
