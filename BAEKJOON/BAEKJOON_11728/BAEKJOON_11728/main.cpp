#include <iostream>
#include <algorithm>

using namespace std;

int a[1000001];
int b[1000001];
int c[2000002];

int main(int argc, const char * argv[]) {
    cin.tie(0); ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    
    for (int i=0;i<N;i++){
        cin >> a[i];
    }
    for (int i=0;i<M;i++){
        cin >> b[i];
    }
    
    int n = 0;
    int m = 0;
    int index = 0;
    while (n < N && m < M){
        if (a[n] < b[m]){
            c[index++] = a[n++];
        }
        else{
            c[index++] = b[m++];
        }
    }
    
    while (n<N) c[index++] = a[n++];
    while (m<M) c[index++] = b[m++];
    
    for (int i=0;i<N+M;i++){
        cout << c[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
