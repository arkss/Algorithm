#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    
    for (int t=0;t<T;t++){
        int n;
        cin >> n;
        int amounts[1000];
        
        for (int i=0;i<n;i++){
            cin >> amounts[i];
        }
        
        int count=0;
        for (int i=1;i<n;i++){
            for (int j=0;j<i;j++){
                if (amounts[i] >= amounts[j])
                    count++;
            }
        }
        
        cout << count << "\n";
        
    }
    return 0;
}


