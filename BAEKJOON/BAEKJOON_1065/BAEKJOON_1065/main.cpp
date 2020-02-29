#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    
    cin >> N;
    
    int i;
    int count = 0; // 한수의 개수
    
    if (N<100)
        count+= N;
    else{
        count += 99;
        for(i=100;i<=N;i++){
            int temp = i;
            int h = temp / 100;
            temp = temp % 100;
            int t = temp / 10;
            temp = temp % 10;
            int o = temp;
            
            if (h-t == t-o)
                count++;
//            cout << i <<  " "<<count << endl;
        }
    }
        
    cout << count;
}
