#include <iostream>

using namespace std;

long long padovan[101];

int main(int argc, const char * argv[]) {
    int test_case;
    int i;
    cin >> test_case;
    
    padovan[1] = 1;
    padovan[2] = 1;
    padovan[3] = 1;
    padovan[4] = 2;
    
    
    for (i=5;i<=100;i++){
        padovan[i] = padovan[i-1] + padovan[i-5];
    }

    
    for(i=0;i<test_case;i++){
        int N;
        cin >> N;
        cout << padovan[N] << endl;
    }
}
