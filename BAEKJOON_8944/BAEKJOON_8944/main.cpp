#include <iostream>

using namespace std;

int countFunc(int *keys , int length){
    int root=keys[0];
    int bigger[20];
    int biggerIndex = 0;
    int smaller[20];
    int smallerIndex = 0;
    
    for (int i=1;i<length;i++){
        if (keys[i] > root){
            bigger[biggerIndex++] = keys[i];
        }
        else{
            smaller[smallerIndex++] = keys[i];
        }
    }
    
    return countFunc(bigger, biggerIndex)+ countFunc(smaller, smallerIndex);
}

int main(int argc, const char * argv[]) {
    
    
    int T;
    cin >> T;
    
    for (int t=0;t<T;t++){
        int N;
        cin >> N;
        int keys[20];
        for (int i=0;i<N;i++){
            cin >> keys[i];
        }
        
        int result = countFunc(keys, N);
        cout << result << "\n";
    }
    return 0;
}


/*
 이진 트리
 크면 오른쪽 작으면 왼쪽
 
 똑같은 이진트리를 만드는 순열의 개수는?
 
 [ 아이디어 ]
 
 1. 맨 처음 들어온 애는 변하지 않는다.
 
 
 
 
 [ 입력 ]
 
 test case T
 순열의 길이 n (1<=n<=20)
 순열이 n 개
 
 [ 출력 ]
 
 순열의 개수를 9999991 로 나눈 나머지 출력
 
 */
