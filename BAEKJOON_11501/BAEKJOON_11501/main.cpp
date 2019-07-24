#include <iostream>

using namespace std;

int max(int a,int b){
    return a>b?a:b;
}

void printArr(int *arr, int length){
    for (int i=0;i<length;i++){
        cout << arr[i] << " ";
    }
}

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    for (int t=0;t<T;t++){
        long long n;
        cin >> n;
        
        int days[n];
        
        for (long long i=0;i<n;i++){
            cin >> days[i];
        }
        
        long long profit = 0;
        int maxPrice = days[n-1];
        
        for (long long i=n-2;i>=0;i--){
            maxPrice = max(maxPrice, days[i]);
            if (maxPrice != days[i]){
                profit += maxPrice - days[i];
            }
            
        }
        //    printArr(days, n);
        
        cout << profit << endl;
    }
    return 0;
}

/*
 
 뒤에서 부터 순회하면서 최대값을 저장,
 값이 최대값보다 적으면 차이만큼 이익에 추가해준다.
 
 */
