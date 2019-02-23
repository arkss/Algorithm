#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int score[5];
    int sum = 0;
    int avg;
    
    for(int i=0;i<5;i++){
        cin >> score[i];
        if (score[i] > 40)
            sum += score[i];
        else
            sum += 40;
    }
    avg = sum / 5;
    cout << avg;
    
}
