#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int TenTotal;
    cin >> TenTotal;
    
    int i;
    int NineTotal = 0;
    int book[9];
    
    for (i=0;i<9;i++){
        cin >> book[i];
        NineTotal += book[i];
    }
    
    int result = TenTotal - NineTotal;
    
    cout << result;
}
