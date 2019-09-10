#include <iostream>

using namespace std;

int coe_list[1001][1001];
const int DIV = 10007;



int main(int argc, const char * argv[]) {
    
    int N,K;
    cin >> N >> K;
    
    for (int n=0;n<=N;n++){
        coe_list[n][0] = 1;
        coe_list[n][n] = 1;
        for (int k=1;k<n;k++){
            coe_list[n][k] = coe_list[n-1][k] + coe_list[n-1][k-1];
            coe_list[n][k] %= DIV;
        }
    }
    cout << coe_list[N][K] << "\n";
    return 0;
}
