#include <iostream>

using namespace std;

int fac[13];

int main(int argc, const char * argv[]) {
    int num;
    
    cin >> num;
    
    fac[0] = 1;
    
    for (int i=1;i<=num;i++){
        fac[i] = fac[i-1] * i;
    }
    
    cout << fac[num];
}
