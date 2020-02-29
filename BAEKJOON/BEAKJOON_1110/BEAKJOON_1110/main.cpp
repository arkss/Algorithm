#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {
    int N;
    int count = 0;
    int temp = 0;
    
    cin >> N;
    
    int front,back;
    temp = N;
    while (1){
        
        front = temp / 10;
        back = temp % 10;
        
        temp = back * 10 + (front+back)%10;
        count++;
        
        
        if (N==temp){
            break;
        }
        
        
    }
    cout << count;
    
}
