#include <iostream>

using namespace std;

int x[3], y[3];

int ccw(){
    int a = x[0]*y[1] + x[1]*y[2] + x[2]*y[0];
    int b = x[1]*y[0] + x[2]*y[1] + x[0]*y[2];
    return a-b;
}

int main(int argc, const char * argv[]) {
    
    
    
    for (int i=0;i<3;i++){
        cin >> x[i] >> y[i];
    }
    
    int ccwNum = ccw();
    
    int result;
    if (ccwNum > 0) result = 1;
    else if (ccwNum < 0) result = -1;
    else result = 0;
    
    cout << result << "\n";
    
    return 0;
}
