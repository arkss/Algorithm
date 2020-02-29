#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int i;
    
    while (1){
        char num[5];
        
        cin >> num;
        
        if (num[0] == '0')
            break;
        
        int length = strlen(num);
        
        for(i=0;i<length/2;i++){
            if (num[i] != num[length-1-i]){
                cout << "no" << endl;
                break;
            }
        }
        if (i==length/2)
            cout << "yes" << endl;
            
    }
    
    
    
    
    
}
