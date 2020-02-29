#include <iostream>

using namespace std;

int a[50][50], b[50][50];

void matrixChange(int n,int m){
    for (int i=n;i<=n+2;i++){
        for (int j=m;j<=m+2;j++){
            a[i][j] = 1 - a[i][j];
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int N,M;
    cin >> N >> M;
    
    int count = 0;
    
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            scanf("%1d", &a[i][j]);
        }
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            scanf("%1d", &b[i][j]);
        }
    }
    
    for (int i=0;i<N-2;i++){
        for (int j=0;j<M-2;j++){
            if (a[i][j] != b[i][j]){
                matrixChange(i,j);
                count++;
            }
        }
    }
    
    int flag = 0;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            if (a[i][j] != b[i][j]){
                count = -1;
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    
    cout << count << "\n";
    
    return 0;
}
