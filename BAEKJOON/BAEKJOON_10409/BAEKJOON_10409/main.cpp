#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int time[50];
    
    int n,total;
    cin >> n >> total;
    
    int count = 0;
    
    for (int i=0;i<n;i++){
        cin >> time[i];
        total -= time[i];
        if (total < 0) break;
        count++;
    }
    
    cout << count << endl;
    
    return 0;
}
