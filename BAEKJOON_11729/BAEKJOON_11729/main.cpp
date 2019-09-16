#include <iostream>

using namespace std;

void hanoi(int n,int start, int temp, int end){
    if (n==1){
        cout << start << " " << end << "\n";
    }
    else{
        hanoi(n-1,start,end,temp);
        hanoi(1,start,temp,end);
        hanoi(n-1,temp,start,end);
    }
}

int pow(int a,int n){
    int result = 1;
    for (int i=0;i<n;i++){
        result = result*a;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    cout << pow(2,N)-1 << "\n";
    hanoi(N,1,2,3);
    
    return 0;
}
