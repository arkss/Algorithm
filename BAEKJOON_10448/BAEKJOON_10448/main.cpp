#include <iostream>

using namespace std;

void printArr(int *arr, int length){
    for (int i=0;i<length;i++){
        cout << arr[i] << " " << endl;
    }
}

int main(int argc, const char * argv[]) {
    
    int triangleList[44];
    
    for (int i=0;i<44;i++){
        triangleList[i] = (i+1)*(i+2) /2;
    }
    
//    printArr(triangleList,44);
    
    int T;
    cin >> T;
    
    for (int t=0;t<T;t++){
        int k;
        cin >> k;
        
        int flag = 0;
        for (int i=0;i<44;i++){
            if (flag) break;
            for (int j=0;j<44;j++){
                if (flag) break;
                for (int l=0;l<44;l++){
                    if (k == triangleList[i] + triangleList[j] + triangleList[l]){
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (flag) cout << "1" << endl;
        else cout << "0" << endl;
    }
    
    
    return 0;
}


/*
 
 
 
 3<= k <= 1000
 3개의 triangle numbers 로 표현이 되면 1,
 그렇지 않으면 0 을 출력
 
 k 는 어처피 1000이하 triangle numbers 도 1000 이하까지만 구해주면 된다.
 
 
 n (n+1) /2 > 1000
 n(n+1) > 2000
 n 이 44 일 때까지만 순회해주면 될듯하다.
 */
