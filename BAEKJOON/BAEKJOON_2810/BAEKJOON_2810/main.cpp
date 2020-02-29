#include <iostream>

using namespace std;



int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    string seat;
    cin >> seat;
    
    //string cup = "*";
    int count = 1;
    bool lflag = true;
    for (int i=0;i<N;i++){
        //cup += seat[i];
        
        if (seat[i] == 'L') lflag = !lflag;
        if (lflag) {
            //cup += "*";
            count++;
        }
        
    }
    
    //cout << cup << "\n";
    cout << min(count,N) << "\n";
    
}
