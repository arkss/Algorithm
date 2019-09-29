#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    long long n;
    cin >> n;
    
    for (long long i=1;i<=n;i++){
        long long limit = (i+1LL)*((1LL<<(i+1))-1) + i;
        if (n<=limit){
            cout << i;
            break;
        }
    }
    return 0;
}
