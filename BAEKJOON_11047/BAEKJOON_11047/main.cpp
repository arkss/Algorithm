#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int coin[10];
    int coinNum = 0;
    
    int N,K;
    cin >> N >> K;
    
    for (int i=0;i<N;i++){
        cin >> coin[i];
    }
    
    
    for (int i=N-1;i>=0;i--){
        int temp = K / coin[i];
        coinNum += temp;
        K -= coin[i] * temp;
    }
    
    cout << coinNum << "\n";
    
    
    return 0;
}
