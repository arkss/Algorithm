#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int primeList[1000];
    primeList[0] = 2;
    int index = 1;
    for (int i=3;i<1000;i+=2){
        int j;
        for (j=2;j*j<=i;j++){
            if(i%j==0) break;
        }
        if(j*j>i) {
            primeList[index] = i;
            index++;
        }
    }
    
//    for (int i=0;i<index;i++){
//        cout << primeList[i] << endl;
//    }
    
    int T;
    cin >> T;
    
    for (int t=0;t<T;t++){
        int num;
        cin >> num;
        int flag = 0;
        for(int i=0;i<index;i++){
            if (flag) break;
            for(int j=0;j<index;j++){
                if (flag) break;
                for(int k=0;k<index;k++){
                    if (primeList[i]+primeList[j]+primeList[k] == num){
                        cout << primeList[i] <<" "<< primeList[j] <<" "<<primeList[k] << endl;
                        flag = 1;
                    }
                }
            }
        }
    }
    
    
    
    
    return 0;
}

/*
 
 5보다 큰 홀수는 3개의 소수의 합으로 만들 수 있다.
 
 7<=k<1000
 
 우선 소수를 전부 구해서 배열에 저장
 
 소수의 크기는 1000보다 클 필요는 없다.
 
 임의의 수가 들어왔을 때 어떤 세 개의 소수를 더할지 3중 포문을 돌리면 해결이 된다.
 
 더 좋은 방법?
 
 
 
 */
