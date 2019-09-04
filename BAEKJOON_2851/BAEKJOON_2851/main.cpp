#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int list[10];
    int result = 0;
    int i = 0;
    for (i=0;i<10;i++){
        cin >> list[i];
        
        result += list[i];
        if (result >= 100){
            break;
        }
    }
    
    int up = result - 100;
    int down = 100 - (result-list[i]);
    
    
    if (up <= down){
        cout << result << "\n";
    }
    else{
        cout << result-list[i] << "\n";
    }
}
