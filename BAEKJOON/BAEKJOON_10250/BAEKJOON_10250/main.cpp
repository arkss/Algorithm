#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    for (int t=0;t<T;t++){
        int H,W,N;
        cin >> H >> W >> N;
        
        int number = (N-1) / H + 1;
        int layer = (N-1) % H + 1;
        
        printf("%d%02d\n", layer, number);
    }
    return 0;
}
