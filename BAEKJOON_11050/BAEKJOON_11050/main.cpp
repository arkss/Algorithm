#include <iostream>

using namespace std;

int fac_list[11];

int main(int argc, const char * argv[]) {
    
    fac_list[0] = 1;
    
    for (int i=1;i<11;i++){
        fac_list[i] = fac_list[i-1] * i;
    }
    
    int n,k;
    cin >> n >> k;
    
    cout << fac_list[n] / (fac_list[n-k]*fac_list[k]) << "\n";
    
    
    return 0;
}

