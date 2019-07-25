#include <iostream>
#include <math.h>

using namespace std;

int N,M;

// 배열을 정수로 변환
int listToNum(int *list,int length,int startIndex){
    int num=0;
    
    while(length>0){
        num += list[startIndex] * pow(10,length-1);
        startIndex++;
        startIndex %= N;
        length--;
    }
    
    return num;
}

int main(int argc, const char * argv[]) {
    
    // X와 Y가 각 자리 별로 담김
    int xList[10];
    int yList[10];
    int gamblingList[100];
    
    
    int T;
    cin >> T;
    
    for (int t=0;t<T;t++){
        
        cin >> N >> M;
        
        int X = 0;
        int Y = 0;
        
        for (int i=0;i<M;i++){
            cin >> xList[i];
        }
        for (int i=0;i<M;i++){
            cin >> yList[i];
        }
        for (int i=0;i<N;i++){
            cin >> gamblingList[i];
        }
        
        X = listToNum(xList, M, 0);
        Y = listToNum(yList, M, 0);
        
        
        
        int validNum = 0;
        
        for (int i=0;i<N;i++){
            int gamblingNum = listToNum(gamblingList, M, i);
            
            if (X<=gamblingNum && gamblingNum<=Y)
                validNum++;
        }
        
        cout << validNum << endl;
    }
    return 0;
}

/*
 
 gambling machine N등분
 각 부분에는 0~9사이의 숫자
 
 임의의 M 자리 수 X,Y(X<=Y) , 이 수는 0으로 시작가능
 
 
 [ 입력 ]
 
 test case T
 N(등분),(1 ≤ N ≤ 100), M(자리수),(1 ≤ M ≤ 9, M ≤ N)
 X
 Y
 돌림판에 들어갈 수 숫자들
 
 
 [ 출력 ]
  X ≤ Z ≤ Y 인 M자리의 수 Z가 몇 개?
 
 */
