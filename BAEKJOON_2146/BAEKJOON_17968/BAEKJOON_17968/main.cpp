#include <iostream>

using namespace std;

int A[1001] = {1,1};

int main(int argc, const char * argv[]) {
    
    for (int i=2;i<1001;i++){
        int value = 1;
        while (1){
            A[i] = value;
            int k=1;
            while (1){
                if (i-2*k<0) break;
                if (A[i] - A[i-k] == A[i-k] - A[i-2*k])
                    break;
                k++;
            }
            if (i-2*k<0)
                break;
            else
                value++;
        }
    }
    
    int n;
    
    cin >> n;
    cout << A[n] << "\n";
}
