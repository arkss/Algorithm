#include <iostream>

using namespace std;

int gcd(int a,int b){
    int temp;
    while (b != 0){
        temp = a % b;
        a = b;
        b = temp;
    }
    
    return a;
}

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    for (int t=0;t<T;t++){

        int a,b;
        cin >> a >> b;
        
        int x;
        while(a!=1){
            x = int(b/a) + 1;
            
            a = a*x - b;
            b = b * x;
            
            int g = gcd(a,b);
            
            if (g!=1){
                a = a / g;
                b = b / g;
            }
        }
        
        cout << b << "\n";
    }
}
