#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int h,w;
    cin >> h >> w;
    
    int count;
    
    if (h==1) count = 1;
    else if (h==2) count = min(4,(w+1)/2);
    else if (h>=3){
        if (w >= 7) count = w-2;
        else count = min(4,w);
    }
    
    cout << count << "\n";
    return 0;
}

