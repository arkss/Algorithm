#include <iostream>

using namespace std;

int r,c;

int pow(int n){
    int result = 1;
    for (int i=0;i<n;i++){
        result = result * 2;
    }
    return result;
}

int value = 0;
void solve(int y, int x, int N){
    if (y==r && x==c) {
        cout << value << "\n";
        return;
    }
    
    else if (N==1) value++;
    else if (!(y<=r && r<y+N && x<=c && c<x+N)){
        value += N*N;
        return;
    }
    
    int M = N/2;
    
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            solve(y+M*i,x+M*j,N/2);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N >> r >> c;

    solve(0,0,pow(N));
    
    return 0;
}
