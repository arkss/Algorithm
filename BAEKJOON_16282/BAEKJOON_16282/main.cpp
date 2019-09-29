#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    long long n;
    cin >> n;
    
    long long powerOfTwo = 2;
    for (long long i=1;i<=n;i++){
        powerOfTwo *= 2;
        long long limit = (i+1)*(powerOfTwo-1) + i;

        if (n<=limit){
            cout << i;
            break;
        }
    }
    return 0;
}
