#include <iostream>

using namespace std;

int grid[100][100];

void printArr(int M,int N){
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    for (int t=0;t<T;t++){
        
        int M,N;
        cin >> M >> N;
        
        for (int i=0;i<M;i++){
            for (int j=0;j<N;j++){
                cin >> grid[i][j];
            }
        }
        // 총 이동거리
        int totalDis = 0;
        for (int col=0;col<N;col++){
            // 해당 column 에서 바닥에 쌓인 갯수
            int dump = 0;
            for (int row=M-1;row>=0;row--){
                if (grid[row][col] == 1){
                    totalDis += (M-1)-row-dump;
                    dump++;
                }
            }
        }
        //printArr(M,N);
        
        cout << totalDis << endl;
    }
    return 0;
}

/*
 [ 입력 ]
 test case T
 m,n (1 ≤ m, n ≤ 100)
 
 
 */
