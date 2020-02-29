#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int e,f,c;
    cin >> e >> f >> c;
    
    int empties = e + f;
    int newBottle = 0;
    
    while (empties / c != 0){
        int temp = empties / c;
        newBottle += temp;
        empties = empties % c;
        empties += temp;
    }
    
    cout << newBottle << "\n";
    
    
    return 0;
}
