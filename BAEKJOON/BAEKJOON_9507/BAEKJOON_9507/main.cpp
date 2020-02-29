#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    long long koong[68] = {1,1,2,4};
    
    for (int i=4;i<68;i++){
        koong[i] = koong[i-1] + koong[i-2] + koong[i-3] + koong[i-4];
    }
    
//    for (int i=0;i<68;i++){
//        cout << koong[i] << " ";
//    }
    
    int T;
    cin >> T;
    for (int t=0;t<T;t++){
        int N;
        cin >> N;
        cout << koong[N] << "\n";
    }
    
    return 0;
}
