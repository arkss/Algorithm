#include <iostream>

using namespace std;

//int graph[1001][1001];



void printArr(int N){
    for (int i=1;i<N;i++){
        for (int j=1;j<N-i+1;j++){
            //  cout << graph[i][j];
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    for (int t=0;t<T;t++){
        
        int redCount[1001] = {0,};
        int N;
        cin >> N;
        
        for (int i=1;i<N;i++){
            for (int j=1;j<N-i+1;j++){
                int input;
                cin >> input;
                redCount[i] += input;
                redCount[j+i] += input;
            }
        }
        
        //    for (int i=1;i<=N;i++){
        //        cout << redCount[i] << " ";
        //    }
        //    cout << endl;
        
        //    printArr(N);
        
        int totalNum = N * (N-1) * (N-2) / 6;
        int errorNum = 0;
        
        for (int i=1;i<=N;i++){
            // 빨간 선의 수 * 파란 선의 수 (삼각형이 안만들어지는 경우)
            errorNum += redCount[i] * (N-redCount[i]-1);
        }
        
        //cout << totalNum << " " << errorNum << endl;
        cout << totalNum - errorNum / 2 << "\n";
        
        
    }
    
    return 0;
}


/*
 N corners(점)
 N*(N-1)/2 luminous tubes(선분)
 선분은 파랑 or 빨강
 
 삼각형을 선택
 색이 다 같아야함
 
 삼각형의 개수는?
 
 dfs 로 순회하면서 같은 색이 3번 나오고 원점으로 돌아오면 count++
 겹치는게 너무 많이 생긴다.
 
 [ 입력 ]
 
 test case T
 점의 수 N (3<=N<=1000)
 i 번째 줄에 점 i 와 연결된 선분이 주어짐
 i+1 부터 N 번까지
 (빨강 : 1, 파랑 : 0)
 
 
 [ 출력 ]
 
 삼각형의 개수를 출력
 */

