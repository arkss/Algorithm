#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int hour , min;
    
    cin >> hour >> min;
    
    
    if (min-45 >= 0){
        min -= 45;
    }
    
    else if(!hour){
        hour = 23;
        min += 15;
    }
    else{
        hour--;
        min += 15;
    }
    
    cout << hour << " "<< min;
}
